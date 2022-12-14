// pch
#include "OnyxPch.h"

#include "Application.h"


namespace Onyx
{
	Application::Application()
	{
	}

	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);

		///////// DEBUG //////////
		ONYX_CORE_TRACE("{0}", e);
		//////////////////////////

	}
	
	void Application::Run()
	{
		while (true);
	}
	
	Application::~Application()
	{
	}
}