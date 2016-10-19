#pragma once
#include <iostream>
#include <string>

enum GameEntityType
{
	egetBase,
	egetPlayer,
	egetDoor,
	egetKey,
	egetWall,
	egetMeleeEnemy,
	egetRangeEnemy,
	egetHealingSmoke,
	egetPoisonGas,
	egetHealthPickUp,

	egetNumTypes
};

class GameEntity
{
public:
	GameEntity();
	virtual ~GameEntity();

	virtual void SaveAsText(std::ostream& outputStream);
	virtual void LoadFromText(std::istream& inputStream);

	virtual void Render(Gdiplus::Graphics& canvas, const CRect& clientRect);

public:
	GameEntityType type;
	Vector2i location;
	std::string name;
	std::string imageName;
	float rotation;
	float xScale;
	float yScale;

protected:
	virtual void SaveAsText_Internal(std::ostream& outputStream);
	virtual void LoadFromText_Internal(std::istream& inputStream);
};

