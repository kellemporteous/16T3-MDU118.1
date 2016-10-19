#include "stdafx.h"
#include "PoisonGas.h"


PoisonGas::PoisonGas():
	GameEntity()
{
	type = egetPoisonGas;
}


PoisonGas::~PoisonGas()
{
}

void PoisonGas::Render(Gdiplus::Graphics& canvas, const CRect& clientRect)
{
	ImageWrapper* imageposionGas = GameFrameworkInstance.GetLoadedImage("PosionGas");
	GameFrameworkInstance.DrawImage(canvas, location, imageposionGas);
}

void PoisonGas::SaveAsText_Internal(std::ostream& outputStream)
{
	outputStream << "," << damage;
	outputStream << "," << AOE;
	outputStream << "," << duration;


}
void PoisonGas::LoadFromText_Internal(std::istream& inputStream)
{
	char dummyChar;
	inputStream >> dummyChar >> damage;
	inputStream >> dummyChar >> AOE;
	inputStream >> dummyChar >> duration;

}