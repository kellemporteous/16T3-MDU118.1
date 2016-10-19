#include "stdafx.h"
#include "Player.h"


Player::Player():
	GameEntity()
{
	type = egetPlayer;
}


Player::~Player()
{
}


void Player::Render(Gdiplus::Graphics& canvas, const CRect& clientRect)
{
	ImageWrapper* imageplayer = GameFrameworkInstance.GetLoadedImage("Player");
	GameFrameworkInstance.DrawImage(canvas, location, imageplayer);
}

void Player::SaveAsText_Internal(std::ostream& outputStream)
{
	outputStream << "," << health;
	outputStream << "," << damage;
	outputStream << "," << atkRange;
	outputStream << "," << moveSpeed;
}
void Player::LoadFromText_Internal(std::istream& inputStream)
{
	char dummyChar;
	inputStream >> dummyChar >> health;
	inputStream >> dummyChar >> damage;
	inputStream >> dummyChar >> atkRange;
	inputStream >> dummyChar >> moveSpeed;
}
