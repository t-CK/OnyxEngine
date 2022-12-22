#include <Onyx.h>

class TestLayer :
	public Onyx::Layer
{
public:
	TestLayer() :
		Layer("TestLayer") { }

	void OnUpdate() override { ONYX_INFO("TestLayer Update"); }

	void OnEvent(Onyx::Event& event) override { }

	~TestLayer() { }
};

class SandboxApp :
	public Onyx::Application
{
public:
	SandboxApp()
	{
		PushLayer(new TestLayer);
		PushOverlay(new TestLayer);
	}

	~SandboxApp()
	{

	}
};

Onyx::Application* Onyx::CreateApplication()
{
	return new SandboxApp();
}