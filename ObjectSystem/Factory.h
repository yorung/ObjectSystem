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

class AFFactory
{
public:
	AFFactory();
	virtual bool IsCapable(const char* ObjectName) = 0;
	virtual AFObject* Create(const char* ObjectName) = 0;
};

extern AFFactoryManager FactoryManager;
