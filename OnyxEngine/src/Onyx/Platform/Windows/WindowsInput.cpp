// pch
#include "OnyxPch.h"
// Onyx engine
#include "WindowsInput.h"
#include "Onyx/Application.h"
// Vendor
#include <GLFW/glfw3.h>

namespace Onyx
{
	Input* Input::s_Instance = new WindowsInput();

	bool WindowsInput::IsKeyPressed_Impl(int keycode)
	{
		auto wnd = static_cast<GLFWwindow*>(Application::Get()->GetWindow().GetNativeWindow());
		auto state = glfwGetKey(wnd, keycode);
		return state == GLFW_PRESS || GLFW_REPEAT;
	}

	bool WindowsInput::IsMouseButtonPressed_Impl(int btn)
	{
		auto wnd = static_cast<GLFWwindow*>(Application::Get()->GetWindow().GetNativeWindow());
		
		auto state = glfwGetMouseButton(wnd, btn);
		return state == GLFW_PRESS;
	}

	std::pair<float, float> WindowsInput::GetMousePos_Impl()
	{
		auto wnd = static_cast<GLFWwindow*>(Application::Get()->GetWindow().GetNativeWindow());
		double x, y;
		glfwGetCursorPos(wnd, &x, &y);
		return std::make_pair(x, y);
	}

	float WindowsInput::GetMouseX_Impl()
	{
		auto [x, y] = GetMousePos_Impl();
		return x;
	}

	float WindowsInput::GetMouseY_Impl()
	{
		auto [x, y] = GetMousePos_Impl();
		return y;
	}
}
