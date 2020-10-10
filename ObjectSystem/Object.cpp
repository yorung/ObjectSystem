#include "Object.h"
#include <cassert>

constexpr int MaxAFObjects = 10000;

class AFObjectManager
{
public:
	void AddObject(AFObject* Object);

	~AFObjectManager();

private:
	int NextAFObject = 0;
	AFObject* GAFObject[MaxAFObjects];
};

AFObjectManager ObjectManager;

void AFObjectManager::AddObject(AFObject* Object)
{
	assert(NextAFObject < MaxAFObjects);
	GAFObject[NextAFObject++] = Object;
}

AFObjectManager::~AFObjectManager()
{
	for (int i = 0; i < NextAFObject; i++)
	{
		delete GAFObject[i];
	}
}

AFObject::AFObject()
{
	ObjectManager.AddObject(this);
}
