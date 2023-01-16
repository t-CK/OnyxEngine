// pch
#include "OnyxPch.h"
// Onyx engine
#include "Application.h"
#include "Platform/Windows/WindowsWindowGL.h"
// Vendor
#include <glad/glad.h>


namespace Onyx
{
	Application* Application::s_Application = nullptr;

	Application::Application()
	{
		ONYX_CORE_ASSERT(!s_Application, "Application allready exists");
		s_Application = this;

		m_AppWindow = std::unique_ptr<Window>(Window::Create());
		m_AppWindow->SetEventCallback(BIND_EVENT_FN(Application::OnEvent));
		
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
		
		///////// DEBUG //////////
		ONYX_CORE_TRACE("{0}", e);
		//////////////////////////

		for (auto it = m_LayerStack.end(); it != m_LayerStack.begin(); )
		{
			(*--it)->OnEvent(e);
			if (e.GetHandeled())
				break;
		}

		if (e.GetEventType() == EventType::WindowClose)
			dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(Application::OnWindowClosed));


	}

	void Application::PushLayer(Layer* layer)
	{
		m_LayerStack.OnLayerInsert(layer);
		layer->OnAttach();
	}

	void Application::PushOverlay(Layer* overlay)
	{
		m_LayerStack.OnOverlayPush(overlay);
		overlay->OnAttach();
	}

	void Application::Run()
	{
		while (m_IsRunning)
		{
			glClearColor(1, 0, 1, 0);
			glClear(GL_COLOR_BUFFER_BIT);

			for (Layer* layer : m_LayerStack)
				layer->OnUpdate();

			m_AppWindow->OnUpdate();
		}
	}
	
	bool Application::OnWindowClosed(WindowCloseEvent)
	{
		m_IsRunning = false;
		
		return m_IsRunning;
	}

	Application::~Application()
	{

	}
}