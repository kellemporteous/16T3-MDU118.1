#include "stdafx.h"
#include "HealingSmoke.h"


HealingSmoke::HealingSmoke():
	GameEntity()
{
	type = egetHealingSmoke;
}


HealingSmoke::~HealingSmoke()
{
}

void HealingSmoke::Render(Gdiplus::Graphics& canvas, const CRect& clientRect)
{
	ImageWrapper* imagehealingSmoke = GameFrameworkInstance.GetLoadedImage("HealingSmoke");
	GameFrameworkInstance.DrawImage(canvas, location, imagehealingSmoke);
}

void HealingSmoke::SaveAsText_Internal(std::ostream& outputStream)
{
	outputStream << "," << addHealth;
	outputStream << "," << AOE;
	outputStream << "," << duration;

}
void HealingSmoke::LoadFromText_Internal(std::istream& inputStream)
{
	char dummyChar;
	inputStream >> dummyChar >> addHealth;
	inputStream >> dummyChar >> AOE;
	inputStream >> dummyChar >> duration;

}
