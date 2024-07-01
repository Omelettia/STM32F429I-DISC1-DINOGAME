#include "CloudManager.hpp"

CloudManager::CloudManager() {

}

void CloudManager::initializeClouds() {
    // Initialize random seed
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 gen(rd()); // seed the generator
    std::uniform_int_distribution<> dis_positiony(16, 30);

    // Initialize clouds
    for (int i = 0; i < NUM_CLOUDS; ++i) {
        int x = (2 - i) * 65 + 20; // Random x position
        int y = dis_positiony(gen); // Random y position
        float speed = i * 0.7f + 1.3f; // Random speed between 1.0 and 3.0
        clouds[i].init(x, y, touchgfx::Bitmap(1), speed);
    }
}

void CloudManager::updateClouds() {
    // Update each cloud's position
    for (int i = 0; i < NUM_CLOUDS; ++i) {
        if (clouds[i].isVisible) {
            // Move the cloud horizontally
            clouds[i].moveRelative(-clouds[i].speed, 0);
            if (clouds[i].getX() + clouds[i].getWidth() < 0) {
                clouds[i].setXY(SCREEN_WIDTH, clouds[i].getY()); // Reset cloud off-screen
            }
        }
    }
}
