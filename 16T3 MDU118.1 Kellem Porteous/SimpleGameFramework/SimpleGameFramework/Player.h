#pragma once
#include "GameEntity.h"

class Player:
	public GameEntity
{
public:
	Player();
	virtual ~Player();

	int health;
	int damage;
	int atkRange;
	int moveSpeed;

protected:
	virtual void SaveAsText_Internal(std::ostream& outputStream);
	virtual void LoadFromText_Internal(std::istream& inputStream);

	virtual void Render(Gdiplus::Graphics& canvas, const CRect& clientRect);

};

