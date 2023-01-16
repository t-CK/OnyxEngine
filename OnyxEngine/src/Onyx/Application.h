#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "Events/KeyEvent.h"
#include "Events/MouseEvent.h"
#include "Events/ApplicationEvent.h"
#include "Window.h"
#include "LayerStack.h"

namespace Onyx
{
	class ONYX_API Application
	{
	public:
		Application();

		void Init();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);

		void Run();

		bool OnWindowClosed(WindowCloseEvent);

		static inline Application* Get() { return s_Application; }
		inline Window& GetWindow() { return *m_AppWindow; }

		virtual ~Application();

	// Class objects
	private:
		std::unique_ptr<Window> m_AppWindow;
		static Application* s_Application;
		LayerStack m_LayerStack;

	// Class variables
	private:
		bool m_IsRunning;
	};

	// To be defined in client
	static Application* CreateApplication();
}