#pragma once
#include "Object.h"

class AFTexture : public AFObject
{
};

class AFMaterial : public AFObject
{
};

class IAFGraphicDevice : public AFObject
{
public:
	virtual AFTexture* CreateTexture(const char* fileName) = 0;
};
