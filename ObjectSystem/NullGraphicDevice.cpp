#include "GraphicDevice.h"
#include "Factory.h"

class AFNullTexture : public AFTexture
{

};

class AFNullGraphicDevice : public IAFGraphicDevice
{
public:
	AFTexture* CreateTexture(const char* fileName) override
	{
		return new AFNullTexture;
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
	return new AFNullGraphicDevice();
}

static AFGraphicDeviceFactory GraphicDeviceFactory;
