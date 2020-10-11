// ObjectSystem.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Factory.h"
#include "GraphicDevice.h"

int main()
{
	IAFGraphicDevice* Device = FactoryManager.Create<IAFGraphicDevice>("GraphicDevice.gd");
	AFTexture* Texture = Device->CreateTexture("MyTexture.png");
}
