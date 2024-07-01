#ifndef CLOUD_MANAGER_HPP
#define CLOUD_MANAGER_HPP

#include <array>
#include <random>
#include "Entity.hpp"

class CloudManager {
public:
    CloudManager();
    void initializeClouds();
    void updateClouds();
    static const int NUM_CLOUDS = 2; // Number of clouds
    std::array<Entity, NUM_CLOUDS> clouds;

private:
    const int SCREEN_WIDTH = 320;
    const int SCREEN_HEIGHT = 230;
};

#endif // CLOUD_MANAGER_HPP
