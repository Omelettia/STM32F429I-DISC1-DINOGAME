#ifndef SCREEN2VIEW_HPP
#define SCREEN2VIEW_HPP

#include <gui_generated/screen2_screen/Screen2ViewBase.hpp>
#include <gui/screen2_screen/Screen2Presenter.hpp>

class Screen2View : public Screen2ViewBase
{
public:
    Screen2View();
    virtual ~Screen2View() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void handleTickEvent();
    virtual void updatePoint(int newValue);
    virtual void updateHearts();
    virtual void resetGame();
    virtual bool checkCollision(const Image& img1, const Image& img2);
    Unicode::UnicodeChar txtBuffer[10];
protected:
    int16_t localImageX;
    int16_t localImageY;
    uint32_t tickCount;
    uint32_t flickerCount;
    bool flickering;
    uint8_t lives;
};

#endif // SCREEN2VIEW_HPP
