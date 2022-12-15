// pch
#include "OnyxPch.h"
// Onyx engine
#include "Application.h"
#include "Platform/Windows/WindowsWindowGL.h"
// Vendor
#include <GLFW/glfw3.h>


namespace Onyx
{
	Application* Application::s_Application = nullptr;

	Application::Application()
	{
		ONYX_CORE_ASSERT(s_Application, "Application allready exists");
		s_Application = this;

		m_AppWindow = std::unique_ptr<Window>(Window::Create());
		Init();
	}

	void Application::Init()
	{
		ONYX_CORE_INFO("Initialized glfw");

		m_IsRunning = true;
	}

	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);

		if (e.GetEventType() == EventType::WindowClose)
			m_IsRunning = false;

		///////// DEBUG //////////
		ONYX_CORE_TRACE("{0}", e);
		//////////////////////////

	}
	
	void Application::Run()
	{
		while (m_IsRunning)
		{
			m_AppWindow->OnUpdate();
		}
	}
	
	Application::~Application()
	{

	}
}