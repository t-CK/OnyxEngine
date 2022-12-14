#pragma once

#ifdef ONYX_PLATFORM_WINDOWS
#include "Application.h"
#include "Log.h"

extern Onyx::Application* Onyx::CreateApplication();

int main(int argc, char** argv)
{
	Onyx::Log::Init();
	auto app = Onyx::CreateApplication();
	
	ONYX_INFO("Created Application");

	app->Run();
	delete app;
}

#endif // ONYX_PLATFORM_WINDOWS
