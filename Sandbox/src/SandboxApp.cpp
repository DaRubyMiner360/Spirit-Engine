#include <SpiritEngine.h>
#include <SpiritEngine/Core/EntryPoint.h>

#include "Sandbox2D.h"
#include "ExampleLayer.h"

class Sandbox : public SpiritEngine::Application
{
public:
	Sandbox()
	{
		// PushLayer(new ExampleLayer());
		PushLayer(new Sandbox2D());
	}

	~Sandbox()
	{
	}
};

SpiritEngine::Application* SpiritEngine::CreateApplication()
{
	return new Sandbox();
}
