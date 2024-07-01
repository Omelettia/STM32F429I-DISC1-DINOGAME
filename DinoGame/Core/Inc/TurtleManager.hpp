#ifndef TURTLE_MANAGER_HPP
#define TURTLE_MANAGER_HPP

#include "Entity.hpp" // Include the Entity class header

class TurtleManager {
public:
    static const int MAX_TURTLES = 2; // Maximum number of turtles
    Entity turtles[MAX_TURTLES]; // Array of Entity objects for turtles
    void initializeTurtles();
    void updateTurtles(int tickCounter, float speed);

private:

};
#endif // TURTLE_MANAGER_HPP
