// ObjectSystem.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Factory.h"

class AFTexture : public AFObject
{
};

class AFMaterial : public AFObject
{
};

class AFGraphicDevice : public AFObject
{
public:
	AFTexture* CreateTexture(const char* fileName)
	{
		return new AFTexture;
	}
};

class AFGraphicDeviceFactory : public AFFactory
{
public:
	virtual bool IsCapable(const char* objectName) override;
	virtual AFObject* Create(const char* objectName) override;
};

bool AFGraphicDeviceFactory::IsCapable(const char* objectName)
{
	return strstr(objectName, ".gd") != nullptr;
}

AFObject* AFGraphicDeviceFactory::Create(const char* objectName)
{
	return new AFGraphicDevice();
}
static AFGraphicDeviceFactory GraphicDeviceFactory;

int main()
{
	AFGraphicDevice* Device = FactoryManager.Create<AFGraphicDevice>("GraphicDevice.gd");
	AFTexture* Texture = Device->CreateTexture("MyTexture.png");
}
