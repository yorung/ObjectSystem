#include "Factory.h"

AFFactoryManager FactoryManager;

AFObject* AFFactoryManager::Create(const char* objectName)
{
	for (auto&& It : Factories)
	{
		if (It->IsCapable(objectName))
		{
			return It->Create(objectName);
		}
	}
	return nullptr;
}

AFFactory::AFFactory()
{
	FactoryManager.Factories.push_back(this);
}
