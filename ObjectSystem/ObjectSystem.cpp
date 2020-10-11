// ObjectSystem.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Factory.h"
#include "GraphicDevice.h"

struct Vector
{
	float X, Y, Z;
};

int main()
{
	AFGraphicDevice* Device = FactoryManager.Create<AFGraphicDevice>("GraphicDevice.gd");
	AFPipeline* Pipeline = Device->CreatePipeline("MyPipeline.pipeline");
	AFDescriptor* Descriptor = Device->CreateDescriptor("MyDescriptor.descriptor");
	AFCommandList* CommandList = Device->CreateCommandList();
	CommandList->SetPipeline(Pipeline);
	CommandList->SetDescriptor(0, Descriptor);

	std::vector<uint32_t> Indices;
	Indices.push_back(0);
	Indices.push_back(1);
	Indices.push_back(2);
	Indices.push_back(3);
	int IndexBufferSize = Indices.size() * sizeof(uint32_t);
	AFBuffer* IndexBuffer = Device->CreateBuffer(IndexBufferSize, &Indices[0]);

	std::vector<Vector> Vertices;
	Vertices.resize(4);
	int Size = Vertices.size() * sizeof(Vector);

	CommandList->SetVertexBuffer(Size, &Vertices[0], sizeof(Vector));
	CommandList->SetIndexBuffer(IndexBuffer);
	CommandList->DrawIndexed(AFTopology::TriangleList, 4, 0, 1);
}
