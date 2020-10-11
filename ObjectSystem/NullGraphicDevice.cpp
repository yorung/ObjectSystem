#include "GraphicDevice.h"
#include "Factory.h"

class AFNullTexture : public AFTexture
{
};

class AFNullPipeline : public AFPipeline
{
};

class AFNullDescriptor : public AFDescriptor
{
};

class AFNullBuffer : public AFBuffer
{
};

class AFNullCommandList : public AFCommandList
{
public:
	virtual void SetPipeline(AFPipeline* Pipeline) override;
	virtual void SetDescriptor(int Index, AFDescriptor* Descriptor) override;
	virtual void SetVertexBuffer(int Size, void* Buffer, int Stride) override;
	virtual void SetIndexBuffer(AFBuffer* IndexBuffer) override;
};

void AFNullCommandList::SetPipeline(AFPipeline* Pipeline)
{

}

void AFNullCommandList::SetDescriptor(int Index, AFDescriptor* Descriptor)
{

}

void AFNullCommandList::SetVertexBuffer(int Size, void* Buffer, int Stride)
{

}

void AFNullCommandList::SetIndexBuffer(AFBuffer* IndexBuffer)
{

}

class AFNullGraphicDevice : public IAFGraphicDevice
{
public:
	virtual AFTexture* CreateTexture(const char* FileName) override
	{
		return new AFNullTexture;
	}
	virtual AFCommandList* CreateCommandList() override
	{
		return new AFNullCommandList;
	}
	virtual AFPipeline* CreatePipeline(const char* FileName) override
	{
		return new AFNullPipeline;
	}
	virtual AFDescriptor* CreateDescriptor(const char* FileName) override
	{
		return new AFNullDescriptor;
	}
	virtual AFBuffer* CreateBuffer(int Size, void* Buffer) override
	{
		return new AFNullBuffer;
	}
};

class AFGraphicDeviceFactory : public AFFactory
{
public:
	virtual bool IsCapable(const char* ObjectName) override;
	virtual AFObject* Create(const char* ObjectName) override;
};

bool AFGraphicDeviceFactory::IsCapable(const char* ObjectName)
{
	return strstr(ObjectName, ".gd") != nullptr;
}

AFObject* AFGraphicDeviceFactory::Create(const char* ObjectName)
{
	return new AFNullGraphicDevice();
}

static AFGraphicDeviceFactory GraphicDeviceFactory;
