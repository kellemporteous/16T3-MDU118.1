#include "stdafx.h"
#include "Wall.h"


Wall::Wall():
	GameEntity()
{
	type = egetWall;
}


Wall::~Wall()
{
}

void Wall::Render(Gdiplus::Graphics& canvas, const CRect& clientRect)
{
	ImageWrapper* imagewall = GameFrameworkInstance.GetLoadedImage("Wall");
	GameFrameworkInstance.DrawImage(canvas, location, imagewall);
}

void Wall::SaveAsText_Internal(std::ostream& outputStream)
{

}
void Wall::LoadFromText_Internal(std::istream& inputStream)
{

}
