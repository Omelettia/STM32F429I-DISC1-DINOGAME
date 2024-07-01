#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>

Model::Model() : ImageX(95),ImageY(160), modelListener(0)
{
	modelTickCount = 0;
}

void Model::tick()
{
	modelTickCount++;
}

void Model::updateX(int16_t x)
{
	ImageX = x;
}

void Model::updateY(int16_t y)
{
	ImageY = y;
}

int16_t Model::GetImageX()
{
	return ImageX;
}

int16_t Model::GetImageY()
{
	return ImageY;
}
