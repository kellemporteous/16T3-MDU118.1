#include "stdafx.h"
#include "Key.h"


Key::Key():
	GameEntity()
{
	type = egetKey;
}


Key::~Key()
{
}

void Key::Render(Gdiplus::Graphics& canvas, const CRect& clientRect)
{
	ImageWrapper* imagekey = GameFrameworkInstance.GetLoadedImage("Key");
	GameFrameworkInstance.DrawImage(canvas, location, imagekey);
}

void Key::SaveAsText_Internal(std::ostream& outputStream)
{
	outputStream << "," << pickUpRange;

}
void Key::LoadFromText_Internal(std::istream& inputStream)
{
	char dummyChar;
	inputStream >> dummyChar >> pickUpRange;
}
