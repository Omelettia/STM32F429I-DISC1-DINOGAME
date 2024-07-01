#pragma once
#include "ObstacleManager.hpp"
#include "TurtleManager.hpp"
#include <random>

class JointedObstacleManager {
public:
    JointedObstacleManager();
    void initializeEntities();
    void updateEntities(float speed, int tickCounter);
    ObstacleManager obstacleManager;
    TurtleManager turtleManager;
    int currentObjectX;
    int currentObjectY;
    int currentObjectWidth;
    int currentObjectHeight;

private:
    int currentEntityType; // 0 for obstacle, 1 for turtle
    std::random_device rd;
    std::mt19937 gen;
    std::uniform_int_distribution<> dis_entity_type;
};
