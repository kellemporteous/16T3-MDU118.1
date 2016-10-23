#pragma once
#include "GameEntity.h"

class RangedEnemy:
	public GameEntity
{
public:
	RangedEnemy();
	~RangedEnemy();

	int health;
	int damage;
	int atkRange;
	int moveSpeed;

protected:
	virtual void SaveAsText_Internal(std::ostream& outputStream);
	virtual void LoadFromText_Internal(std::istream& inputStream);

	virtual void Render(Gdiplus::Graphics& canvas, const CRect& clientRect);
};

