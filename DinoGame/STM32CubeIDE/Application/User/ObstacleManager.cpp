#include "ObstacleManager.hpp"

ObstacleManager::ObstacleManager() : gen(rd()), dis_obstacle_type(0, 2) {
    currentObstacleType = -1;
    lastObstacleType = -1;
}

void ObstacleManager::initializeObstacles() {
    // Initialize all obstacles off-screen
    int x =  420 ; // Start off-screen

    obstacles[GREENTREE].init(x, 149, touchgfx::Bitmap(14), 1.0f);
    obstacles[PIPE].init(x, 145, touchgfx::Bitmap(11), 1.0f);
    obstacles[TREE].init(x, 161, touchgfx::Bitmap(15), 1.0f);

}

void ObstacleManager::updateObstacles(float speed) {
    // Check if there's currently an obstacle moving
    if (currentObstacleType == -1) {
        // Select a random obstacle type
        currentObstacleType = dis_obstacle_type(gen);

        // Initialize the chosen obstacle type
        obstacles[currentObstacleType].setVisibility(true);

        // Initialize its position off-screen
        int x = SCREEN_WIDTH + 100; // Start off-screen
        obstacles[currentObstacleType].setX(x);
    }

    // Move the current obstacle type
    if (obstacles[currentObstacleType].isVisible) {
        obstacles[currentObstacleType].moveRelative(-speed, 0);

        // Check if obstacle is off-screen
        if (obstacles[currentObstacleType].getX() + obstacles[currentObstacleType].getWidth() < 0) {
            obstacles[currentObstacleType].setVisibility(false);
            lastObstacleType = currentObstacleType;
            currentObstacleType = -1;
        }
    }
}
