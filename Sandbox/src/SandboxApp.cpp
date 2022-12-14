#include <Onyx.h>

class SandboxApp :
	public Onyx::Application
{
public:
	SandboxApp()
	{

	}

	~SandboxApp()
	{

	}
};

Onyx::Application* Onyx::CreateApplication()
{
	return new SandboxApp();
}