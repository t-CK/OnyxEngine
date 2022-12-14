#pragma once

#include "Core.h"

namespace Onyx
{
	class ONYX_API Application
	{
	public:
		Application();

		void Run();

		virtual ~Application();
	};

	// To be defined in client
	Application* CreateApplication();
}