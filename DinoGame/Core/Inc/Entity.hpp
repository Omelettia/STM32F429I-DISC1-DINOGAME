#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <touchgfx/widgets/Image.hpp>

class Entity : public touchgfx::Image {
public:
    bool isVisible;
    float speed;

    Entity() : isVisible(true), speed(1.0f) {
        // Default constructor
    }

    void init(int x, int y, touchgfx::Bitmap bitmap, float speed = 1.0f) {
        this->setXY(x, y);
        this->isVisible = true;
        this->speed = speed;
        this->setBitmap(bitmap);
    }

    void moveRelative(float dx, float dy) {
        moveTo(getX() + dx, getY() + dy);
    }

    void setVisibility(bool visible) {
        this->isVisible = visible;
    }

    bool getVisibility() const {
        return isVisible;
    }

    int getX() const {
        return Image::getX();
    }

    int getY() const {
        return Image::getY();
    }

};

#endif // ENTITY_HPP
