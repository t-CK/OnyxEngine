#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "Events/KeyEvent.h"
#include "Events/MouseEvent.h"
#include "Events/ApplicationEvent.h"

namespace Onyx
{
	class ONYX_API Application
	{
	public:
		Application();

		void OnEvent(Event& e);

		void Run();

		virtual ~Application();
	};

	// To be defined in client
	Application* CreateApplication();
}