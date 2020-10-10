#pragma once

#include "Object.h"
#include <vector>

class AFFactory;

class AFFactoryManager
{
public:
	std::vector<AFFactory*> Factories;

	AFObject* Create(const char* objectName);

	template<class T>
	T* Create(const char* objectName)
	{
		return dynamic_cast<T*>(Create(objectName));
	}
};

class AFFactory : public AFObject
{
public:
	AFFactory();
	virtual bool IsCapable(const char* objectName) = 0;
	virtual AFObject* Create(const char* objectName) = 0;
};

extern AFFactoryManager FactoryManager;
