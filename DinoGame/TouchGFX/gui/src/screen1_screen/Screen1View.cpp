#include <gui/screen1_screen/Screen1View.hpp>
#include <array>
extern uint16_t JoystickX, JoystickY;
Screen1View::Screen1View()
    : tickCounter(0), isJumping(false), jumpTickCounter(0), currentState(NEUTRAL),gamePaused(false),hiScore(0),speed(3)  // Initialize variables
{

}

void Screen1View::setupScreen()
{
    cloudManager.initializeClouds();
    for (auto& cloud : cloudManager.clouds) {
        add(cloud);
    }

    jointedObstacleManager.initializeEntities();
    for (auto& obstacle : jointedObstacleManager.obstacleManager.obstacles) {
        add(obstacle);
    }
    for (auto& turtle : jointedObstacleManager.turtleManager.turtles) {
        add(turtle);
    }
}

void Screen1View::tearDownScreen()
{
    Screen1ViewBase::tearDownScreen();
}

void Screen1View::handleTickEvent()
{
	if (gamePaused == true)
	{
	if (JoystickX >= 150)
	    		{
	    		  gamePaused = false;
	    		  cloudManager.initializeClouds();
	    		  jointedObstacleManager.initializeEntities();
	    		  tickCounter = 0;
	    		  speed = 3;
	    		  gameover.setVisible(false);
	    		}
	    	else
	            return;
	}
    tickCounter += 1;
    if (tickCounter % 50 == 0)
    {
    	if (speed < 7)
    	speed += 0.1;
    }
    cloudManager.updateClouds();
    jointedObstacleManager.updateEntities(speed, tickCounter);
    // Background animation
    switch (tickCounter % 6)
    {
        case 0:
            background1.setVisible(true);
            background2.setVisible(false);
            background3.setVisible(false);
            break;
        case 2:
            background1.setVisible(false);
            background2.setVisible(true);
            background3.setVisible(false);
            break;
        case 4:
            background1.setVisible(false);
            background2.setVisible(false);
            background3.setVisible(true);
            break;
    }

    if (isJumping)
    {   if (checkCollision(mario6))
    	resetGame();
        jumpTickCounter += 1;
        if (jumpTickCounter <= 15)
        {
            // Going up
            mario6.setY(147 - (132 * jumpTickCounter / 15));  // Move smoothly up to y=15
        }
        else if (jumpTickCounter <= 35)
        {
            // Hover at the peak of the jump
            mario6.setY(15);  // Stay at y=15 for a moment
        }
        else if (jumpTickCounter <= 50)
        {
            // Going down
            mario6.setY(15 + (132 * (jumpTickCounter - 35) / 15));  // Move smoothly down to y=147
        }
        else
        {
            // End of jump
            isJumping = false;
            jumpTickCounter = 0;
        }
    }

    else
    {
        // Check joystick input only if not jumping
        State newState = currentState;
        if (JoystickY > 90 && JoystickY < 150)
        {
            newState = NEUTRAL;
        }
        else if (JoystickY <= 90)
        {
            newState = DUCKING;
        }
        else if (JoystickY >= 150)
        {
            newState = JUMPING;
            isJumping = true;
            jumpTickCounter = 0;
        }

        if (newState != currentState)
        {
            currentState = newState;
            switch (currentState)
            {
                case NEUTRAL:
                    mario2.setVisible(true);
                    mario3.setVisible(false);
                    mario4.setVisible(false);
                    mario5.setVisible(false);
                    mario6.setVisible(false);
                    break;
                case DUCKING:
                    mario2.setVisible(false);
                    mario3.setVisible(false);
                    mario4.setVisible(true);
                    mario5.setVisible(false);
                    mario6.setVisible(false);
                    break;
                case JUMPING:
                    mario2.setVisible(false);
                    mario3.setVisible(false);
                    mario4.setVisible(false);
                    mario5.setVisible(false);
                    mario6.setVisible(true);
                    break;
            }
        }

        if (currentState == NEUTRAL)
        {
            // Neutral joystick - alternate between mario2 and mario3
        	if (checkCollision(mario2))
        		    resetGame();
            switch (tickCounter % 24)
            {
                case 0:
                case 12:
                    mario2.setVisible(true);
                    mario3.setVisible(false);
                    break;
                case 4:
                case 16:
                    mario2.setVisible(false);
                    mario3.setVisible(true);
                    break;
                case 8:
                case 20:
                    mario2.setVisible(true);
                    mario3.setVisible(false);
                    break;
            }
        }
        else if (currentState == DUCKING)
        {
            // Joystick pressed down - alternate between mario5 and mario4
        	if (checkCollision(mario4))
        		 resetGame();
            switch (tickCounter % 24)
            {
                case 0:
                case 12:
                    mario4.setVisible(true);
                    mario5.setVisible(false);
                    break;
                case 4:
                case 16:
                    mario4.setVisible(false);
                    mario5.setVisible(true);
                    break;
                case 8:
                case 20:
                    mario4.setVisible(true);
                    mario5.setVisible(false);
                    break;
            }
        }
    }
    if (tickCounter < 99999*5){
    	updateScores(tickCounter/5);
    }
    invalidate();
}
bool Screen1View::checkCollision(const touchgfx::Image& img1) {
    // Get current object position and dimensions from JointedObstacleManager
    int objX = jointedObstacleManager.currentObjectX;
    int objY = jointedObstacleManager.currentObjectY;
    int objWidth = jointedObstacleManager.currentObjectWidth;
    int objHeight = jointedObstacleManager.currentObjectHeight;

    // Check collision using the provided logic
    return (img1.getX() < objX + objWidth &&
            img1.getX() + img1.getWidth() > objX &&
            img1.getY() < objY + objHeight &&
            img1.getY() + img1.getHeight() > objY);
}

void Screen1View::updateScores(int newValue)
{
    // Format newValue with leading zeros into scoresBuffer
    Unicode::snprintf(scoresBuffer, SCORES_SIZE, "%05d", newValue); // %05d ensures 5 digits with leading zeros
    scores.setWildcard(scoresBuffer);
    scores.invalidate();
}

void Screen1View::updateHiScores(int newValue)
{
    // Format newValue with leading zeros into scoresBuffer
    Unicode::snprintf(hiScoresBuffer, HISCORES_SIZE, "%05d", newValue); // %05d ensures 5 digits with leading zeros
    hiScores.setWildcard(hiScoresBuffer);
    hiScores.invalidate();
}

void Screen1View::resetGame() {
	gamePaused = true;
	if (tickCounter > hiScore*5){
        hiScore = tickCounter / 5; // Update hiScore if current score is higher
        updateHiScores(hiScore);
	    hiScores.setVisible(true);
	    	    }
	gameover.setVisible(true);
}


