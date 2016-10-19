#pragma once
#include "GameEntity.h"

class HealingSmoke:
	public GameEntity
{
public:
	HealingSmoke();
	~HealingSmoke();

	int addHealth;
	int AOE;
	int duration;

protected:
	virtual void SaveAsText_Internal(std::ostream& outputStream);
	virtual void LoadFromText_Internal(std::istream& inputStream);

	virtual void Render(Gdiplus::Graphics& canvas, const CRect& clientRect);

};

