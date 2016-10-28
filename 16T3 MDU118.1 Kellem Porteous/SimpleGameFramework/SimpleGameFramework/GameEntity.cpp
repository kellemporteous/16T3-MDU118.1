#include "stdafx.h"
#include "GameEntity.h"


GameEntity::GameEntity()
{
	type = egetBase;
}


GameEntity::~GameEntity()
{
}
void GameEntity::SaveAsText_Internal(std::ostream& outputStream)
{
	// Save any child specific info
}

void GameEntity::LoadFromText_Internal(std::istream& inputStream)
{
	// load any child specific info
}

void GameEntity::Render(Gdiplus::Graphics& canvas, const CRect& clientRect)
{

}

void GameEntity::SaveAsText(std::ostream& outputStream)
{
	outputStream << type << ","
				 << name << ","
				 << location.X << "," << location.Y << ","
				 << imageName << ","
				 << rotation << ","
				 << xScale << "," << yScale;

	SaveAsText_Internal(outputStream);

	outputStream << std::endl;
}

void GameEntity::LoadFromText(std::istream& inputStream)
{

	char dummyValue;
	// skips comma
	inputStream >> dummyValue;

	// read in up to the comma and store into name
	// throw away the trailing comma
	std::getline(inputStream, name, ',');

	// read in the location
	inputStream >> location.X;
	inputStream >> dummyValue;
	inputStream >> location.Y;

	inputStream >> dummyValue;

	// read in up to the comma and store into name
	// throw away the trailing comma
	std::getline(inputStream, imageName, ',');

	inputStream >> rotation;
	inputStream >> dummyValue;

	inputStream >> xScale;
	inputStream >> dummyValue;
	inputStream >> yScale;

	LoadFromText_Internal(inputStream);
}