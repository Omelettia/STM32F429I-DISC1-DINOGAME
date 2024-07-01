#ifndef OBSTACLEMANAGER_HPP
#define OBSTACLEMANAGER_HPP

#include "Entity.hpp"
#include <random>

class ObstacleManager {
public:
    ObstacleManager();
    void initializeObstacles();
    void updateObstacles(float speed);
    Entity obstacles[3]; // Array of obstacles
    int currentObstacleType;
    int lastObstacleType;

private:

    std::random_device rd;
    std::mt19937 gen;
    std::uniform_int_distribution<int> dis_obstacle_type;

    const int SCREEN_WIDTH = 320;
    const int SCREEN_HEIGHT = 230;

    enum EntityType {
        GREENTREE,
        PIPE,
        TREE
    };

};

#endif // OBSTACLEMANAGER_HPP
