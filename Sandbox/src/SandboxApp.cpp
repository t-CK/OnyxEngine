#include <Onyx.h>

class TestLayer :
	public Onyx::Layer
{
public:
	TestLayer() :
		Layer("TestLayer") { }

	void OnUpdate() override 
	{ 
		ONYX_INFO("TestLayer Update");
		if (Onyx::Input::IsKeyPressed(ONYX_KEY_TAB))
			ONYX_TRACE("Tab is pressed");
	}

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
		PushOverlay(new Onyx::ImGuiLayer());
	}

	~SandboxApp()
	{

	}
};

Onyx::Application* Onyx::CreateApplication()
{
	return new SandboxApp();
}