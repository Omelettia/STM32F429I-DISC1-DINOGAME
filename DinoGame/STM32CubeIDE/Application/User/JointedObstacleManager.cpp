#include "JointedObstacleManager.hpp"

JointedObstacleManager::JointedObstacleManager() : gen(rd()), dis_entity_type(0, 1), currentEntityType(-1) {
    currentObjectX = 500;
    currentObjectY = 500;
    currentObjectWidth = 0;
    currentObjectHeight = 0;
}

void JointedObstacleManager::initializeEntities() {
    obstacleManager.initializeObstacles();
    turtleManager.initializeTurtles();
}

void JointedObstacleManager::updateEntities(float speed, int tickCounter) {
    if (currentEntityType == -1) {
        currentEntityType = dis_entity_type(gen);
    }
    if (currentEntityType == 0)
    {
    	if (!obstacleManager.obstacles[obstacleManager.lastObstacleType].getVisibility())
    	{
    	   currentEntityType = -1;
    	   obstacleManager.obstacles[obstacleManager.lastObstacleType].setVisibility(true);
    	} else
		obstacleManager.updateObstacles(speed);
        currentObjectX = obstacleManager.obstacles[obstacleManager.currentObstacleType].getX();
        currentObjectY = obstacleManager.obstacles[obstacleManager.currentObstacleType].getY();
        currentObjectWidth = obstacleManager.obstacles[obstacleManager.currentObstacleType].getWidth();
        currentObjectHeight = obstacleManager.obstacles[obstacleManager.currentObstacleType].getHeight();
    }
    if (currentEntityType == 1)
    {  if (!turtleManager.turtles[0].getVisibility()) {
        currentEntityType = -1;
        turtleManager.turtles[0].setVisibility(true);
    } else
        turtleManager.updateTurtles(tickCounter,speed);
        currentObjectX = turtleManager.turtles[0].getX();
        currentObjectY = turtleManager.turtles[0].getY();
        currentObjectWidth = turtleManager.turtles[0].getWidth();
        currentObjectHeight = turtleManager.turtles[0].getHeight();
    }
}
