#include "TurtleManager.hpp"
#include <random>

// Bitmap definitions (adjust as per your actual bitmap IDs)
touchgfx::Bitmap turtle1Bitmap(17);
touchgfx::Bitmap turtle2Bitmap(18);

const int SCREEN_WIDTH = 320;
const int SCREEN_HEIGHT = 230;

void TurtleManager::initializeTurtles() {
    // Initialize random seed
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 gen(rd()); // seed the generator
    std::uniform_real_distribution<> dis_speed(1.0f, 3.0f); // define the range for speed

    // Generate common position and speed
    int posX = 420;
    int posY = 95;
    float speed = dis_speed(gen);

    // Initialize turtles with the same position and speed
    turtles[0].init(posX, posY, turtle1Bitmap, speed);
    turtles[1].init(posX, posY, turtle2Bitmap, speed);
}

void TurtleManager::updateTurtles(int tickCounter, float speed) {
    // Manage visibility based on tickCounter
    switch (tickCounter % 24) {
        case 0:
        case 12:
        case 8:
        case 20:
            turtles[0].setVisible(true);
            turtles[1].setVisible(false);
            break;
        case 4:
        case 16:
            turtles[0].setVisible(false);
            turtles[1].setVisible(true);
            break;
    }

    // Update each turtle's position
    for (int i = 0; i < MAX_TURTLES; ++i) {
            // Move the turtle horizontally
            turtles[i].moveRelative(-speed, 0); // Adjust speed as needed
            if (turtles[i].getX() + turtles[i].getWidth() < 0) {
                turtles[i].moveTo(SCREEN_WIDTH, turtles[i].getY());
                turtles[i].setVisibility(false);
        }
    }
}
