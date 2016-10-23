#include "stdafx.h"
#include "MeleeEnemy.h"


MeleeEnemy::MeleeEnemy():
	GameEntity()
{
	type = egetMeleeEnemy;
}


MeleeEnemy::~MeleeEnemy()
{
}

void MeleeEnemy::Render(Gdiplus::Graphics& canvas, const CRect& clientRect)
{
	ImageWrapper* imageMeleeEnemy = GameFrameworkInstance.GetLoadedImage("MeleeEnemy");
	GameFrameworkInstance.DrawImage(canvas, location, imageMeleeEnemy);
}

void MeleeEnemy::SaveAsText_Internal(std::ostream& outputStream)
{
	outputStream << "," << health;
	outputStream << "," << damage;
	outputStream << "," << atkRange;
	outputStream << "," << moveSpeed;
}
void MeleeEnemy::LoadFromText_Internal(std::istream& inputStream)
{
	char dummyChar;
	inputStream >> dummyChar >> health;
	inputStream >> dummyChar >> damage;
	inputStream >> dummyChar >> atkRange;
	inputStream >> dummyChar >> moveSpeed;
}