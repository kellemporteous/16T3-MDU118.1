#include "stdafx.h"
#include "RangedEnemy.h"


RangedEnemy::RangedEnemy()
{
	type = egetRangeEnemy;
}


RangedEnemy::~RangedEnemy()
{
}

void RangedEnemy::Render(Gdiplus::Graphics& canvas, const CRect& clientRect)
{
	ImageWrapper* imageRangedEnemy = GameFrameworkInstance.GetLoadedImage("RangedEnemy");
	GameFrameworkInstance.DrawImage(canvas, location, imageRangedEnemy);
}

void RangedEnemy::SaveAsText_Internal(std::ostream& outputStream)
{
	outputStream << "," << health;
	outputStream << "," << damage;
	outputStream << "," << atkRange;
	outputStream << "," << moveSpeed;
}
void RangedEnemy::LoadFromText_Internal(std::istream& inputStream)
{
	char dummyChar;
	inputStream >> dummyChar >> health;
	inputStream >> dummyChar >> damage;
	inputStream >> dummyChar >> atkRange;
	inputStream >> dummyChar >> moveSpeed;
}