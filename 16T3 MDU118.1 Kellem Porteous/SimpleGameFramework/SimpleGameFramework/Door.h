#pragma once
#include "GameEntity.h"

class Door:
	public GameEntity
{
public:
	Door();
	~Door();


protected:
	virtual void SaveAsText_Internal(std::ostream& outputStream);
	virtual void LoadFromText_Internal(std::istream& inputStream);

	virtual void Render(Gdiplus::Graphics& canvas, const CRect& clientRect);
};

