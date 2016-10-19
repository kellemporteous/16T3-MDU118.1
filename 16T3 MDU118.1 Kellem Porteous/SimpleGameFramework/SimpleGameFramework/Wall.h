#pragma once
#include "GameEntity.h"

class Wall:
	public GameEntity
{
public:
	Wall();
	~Wall();

protected:
	virtual void SaveAsText_Internal(std::ostream& outputStream);
	virtual void LoadFromText_Internal(std::istream& inputStream);

	virtual void Render(Gdiplus::Graphics& canvas, const CRect& clientRect);

};

