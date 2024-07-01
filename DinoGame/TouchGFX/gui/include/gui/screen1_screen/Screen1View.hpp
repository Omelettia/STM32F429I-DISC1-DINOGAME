#ifndef SCREEN1VIEW_HPP
#define SCREEN1VIEW_HPP

#include <gui_generated/screen1_screen/Screen1ViewBase.hpp>
#include <gui/screen1_screen/Screen1Presenter.hpp>
#include "CloudManager.hpp"
#include "JointedObstacleManager.hpp"
class Screen1View : public Screen1ViewBase
{
public:
    Screen1View();
    virtual ~Screen1View() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void handleTickEvent();
    virtual void updateScores(int newValue);
    virtual void updateHiScores(int newValue);
    virtual void resetGame();
    bool checkCollision(const touchgfx::Image& img1);

protected:
    long tickCounter = 0;
    long hiScore = 0;
    float speed = 3;
    bool isJumping;
    bool gamePaused;
    uint8_t jumpTickCounter = 0;
    JointedObstacleManager jointedObstacleManager;
    CloudManager cloudManager;
    enum State {
        NEUTRAL,
        DUCKING,
        JUMPING
    };
    State currentState;
};

#endif // SCREEN1VIEW_HPP
