#pragma once
#include "Object.h"
#include <cstdint>

enum class AFTopology : uint8_t
{
	TriangleStrip,
	TriangleList,
	LineList,
};

class AFBuffer : public AFObject
{
};

class AFTexture : public AFObject
{
};

class AFMaterial : public AFObject
{
};

class AFDescriptor : public AFObject
{
};

class AFPipeline : public AFObject
{
};

class AFCommandList : public AFObject
{
public:
	virtual void SetDescriptor(int Index, AFDescriptor* Descriptor) = 0;
	virtual void SetPipeline(AFPipeline* Pipeline) = 0;
	virtual void SetVertexBuffer(int Size, void* Buffer, int Stride) = 0;
	virtual void SetIndexBuffer(AFBuffer* IndexBuffer) = 0;
	virtual void DrawIndexed(AFTopology Topology, int NumVertices, int Start = 0, int InstanceCount = 1) = 0;
};

class AFGraphicDevice : public AFObject
{
public:
	virtual AFTexture* CreateTexture(const char* FileName) = 0;
	virtual AFCommandList* CreateCommandList() = 0;
	virtual AFPipeline* CreatePipeline(const char* FileName) = 0;
	virtual AFDescriptor* CreateDescriptor(const char* FileName) = 0;
	virtual AFBuffer* CreateBuffer(int Size, void* Buffer) = 0;
};
