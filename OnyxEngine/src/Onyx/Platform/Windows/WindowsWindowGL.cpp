#pragma once

// pch
#include "OnyxPch.h"
// Onyx Engine
#include "WindowsWindowGL.h"
#include "Onyx/Events/ApplicationEvent.h"
#include "Onyx/Events/KeyEvent.h"
#include "Onyx/Events/MouseEvent.h"
// Vendor

namespace Onyx
{
	static bool s_GLFWInitialized = false;

	// GLFW error callback
	static void GLFWErrorCallback(int errorCode, const char* errorMsg)
	{
		ONYX_CORE_ERROR("GLFW ERROR [{0}]: {1}", errorCode, errorMsg);
	}

	Window* Window::Create(const WindowProps& props)
	{
		return new WindowsWindowGL(props);
	}

	WindowsWindowGL::WindowsWindowGL(const WindowProps& props)
	{
		Init(props);
	}

	void WindowsWindowGL::Init(const WindowProps& props)
	{
		m_Data.m_Title = props.m_Title;
		m_Data.m_Height = props.m_Height;
		m_Data.m_Width = props.m_Width;

		ONYX_CORE_INFO("Creating window {0}, ({1}, {2})", props.m_Title, props.m_Width, props.m_Height);

		if (!s_GLFWInitialized)
		{
			int success = glfwInit();
			ONYX_CORE_ASSERT(success, "Failed to initialize GLFW");

			s_GLFWInitialized = true;
		}


		// Set GLFW error callback
		glfwSetErrorCallback(GLFWErrorCallback);

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

		m_Window = glfwCreateWindow((int)props.m_Width, (int)props.m_Height, props.m_Title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(m_Window);
		glfwSetWindowUserPointer(m_Window, &m_Data);
		SetVSync(true);

		////////////////////////////////////////////////////////////////////////////////////
		//////////////////// Set GLFW event callbacks //////////////////////////////////////
		////////////////////////////////////////////////////////////////////////////////////

		glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int width, int height)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

		data.m_Width = width;
		data.m_Height = height;

		WindowResizeEvent event(width, height);
		data.m_EventCallback(event);
			});

		glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

		WindowCloseEvent event;
		data.m_EventCallback(event);
			});
		////////////////////////////////////////////////////////////////////////////////////
	}

	void WindowsWindowGL::Shutdown()
	{
		glfwDestroyWindow(m_Window);
	}

	void WindowsWindowGL::OnUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers(m_Window);
	}

	void WindowsWindowGL::SetVSync(bool enabled)
	{
		enabled ? glfwSwapInterval(1) : glfwSwapInterval(0);

		m_Data.m_VSync = enabled;
	}

	WindowsWindowGL::~WindowsWindowGL()
	{
		Shutdown();
	}
}