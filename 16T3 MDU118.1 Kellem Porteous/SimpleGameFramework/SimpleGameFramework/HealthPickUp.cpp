#include "stdafx.h"
#include "HealthPickUp.h"


HealthPickUp::HealthPickUp():
	GameEntity()
{
	type = egetHealthPickUp;
}


HealthPickUp::~HealthPickUp()
{
}

void HealthPickUp::Render(Gdiplus::Graphics& canvas, const CRect& clientRect)
{
	ImageWrapper* imagehealingPickUp = GameFrameworkInstance.GetLoadedImage("HealthPickUp");
	GameFrameworkInstance.DrawImage(canvas, location, imagehealingPickUp);
}

void HealthPickUp::SaveAsText_Internal(std::ostream& outputStream)
{
	outputStream << "," << addHealth;
	outputStream << "," << pickUpRange;

}
void HealthPickUp::LoadFromText_Internal(std::istream& inputStream)
{
	char dummyChar;
	inputStream >> dummyChar >> addHealth;
	inputStream >> dummyChar >> pickUpRange;
}
