#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "Events/KeyEvent.h"
#include "Events/MouseEvent.h"
#include "Events/ApplicationEvent.h"
#include "Window.h"

namespace Onyx
{
	class ONYX_API Application
	{
	public:
		Application();

		void Init();

		void OnEvent(Event& e);

		void Run();

		static inline Application* Get() { return s_Application; }

		virtual ~Application();

	// Class objects
	private:
		std::unique_ptr<Window> m_AppWindow;
		static Application* s_Application;

	// Class variables
	private:
		bool m_IsRunning;
	};

	// To be defined in client
	static Application* CreateApplication();
}