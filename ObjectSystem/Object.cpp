#include "Object.h"
#include <cassert>

constexpr int MaxAFObjects = 10000;

class AFObjectManager
{
public:
	void AddObject(AFObject* Object, int& Index);
	void EraseObject(AFObject* Object, int Index);

	~AFObjectManager();

private:
	int NextAFObject = 0;
	AFObject* GAFObject[MaxAFObjects];
};

AFObjectManager ObjectManager;

void AFObjectManager::AddObject(AFObject* Object, int& Index)
{
	assert(NextAFObject < MaxAFObjects);
	Index = NextAFObject;
	GAFObject[NextAFObject++] = Object;
}

void AFObjectManager::EraseObject(AFObject* Object, int Index)
{
	assert(Object != nullptr);
	assert(Index < MaxAFObjects);
	assert(GAFObject[Index] == Object);
	GAFObject[Index] = nullptr;
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
	ObjectManager.AddObject(this, Index);
}

AFObject::~AFObject()
{
	ObjectManager.EraseObject(this, Index);
}
