#include "stdafx.h"
#include "Door.h"


Door::Door():
	GameEntity()
{
	type = egetDoor;
}


Door::~Door()
{
}

void Door::Render(Gdiplus::Graphics& canvas, const CRect& clientRect)
{
	ImageWrapper* imagedoor = GameFrameworkInstance.GetLoadedImage("Door");
	GameFrameworkInstance.DrawImage(canvas, location, imagedoor);
}

void Door::SaveAsText_Internal(std::ostream& outputStream)
{

}
void Door::LoadFromText_Internal(std::istream& inputStream)
{

}