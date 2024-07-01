#ifndef MODEL_HPP
#define MODEL_HPP

#include <stdint.h>
class ModelListener;

class Model
{
public:
    Model();
    long modelTickCount = 0;
    void bind(ModelListener* listener)
    {
        modelListener = listener;
    }

    void tick();
    void updateX(int16_t x);
    void updateY(int16_t y);
    int16_t GetImageX();

    int16_t ImageX;
    int16_t GetImageY();

    int16_t ImageY;
protected:
    ModelListener* modelListener;
};

#endif // MODEL_HPP
