#pragma once

// pch
#include "OnyxPch.h"
// Onyx Engine
#include "WindowsWindowGL.h"
#include "Onyx/Events/ApplicationEvent.h"
#include "Onyx/Events/KeyEvent.h"
#include "Onyx/Events/MouseEvent.h"
// Vendor
#include "glad/glad.h"
#include "GLFW/glfw3.h"

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
		m_Data.Title = props.Title;
		m_Data.Height = props.Height;
		m_Data.Width = props.Width;

		ONYX_CORE_INFO("Creating window {0}, ({1}, {2})", props.Title, props.Width, props.Height);

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

		m_Window = glfwCreateWindow((int)props.Width, (int)props.Height, props.Title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(m_Window);

		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		ONYX_CORE_ASSERT(status, "Failed to initialize glad");

		glfwSetWindowUserPointer(m_Window, &m_Data);
		SetVSync(true);

		////////////////////////////////////////////////////////////////////////////////////
		//////////////////// Set GLFW event callbacks //////////////////////////////////////
		////////////////////////////////////////////////////////////////////////////////////

		glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int width, int height)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				data.Width = width;
				data.Height = height;

				WindowResizeEvent event(width, height);
				data.EventCallback(event);
			});

		glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				WindowCloseEvent event;
				data.EventCallback(event);
			});

		glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				switch (action)
				{
					case GLFW_PRESS:
					{
						KeyPressedEvent event(key, 0);
						data.EventCallback(event);
						break;
					}
					case GLFW_RELEASE:
					{
						KeyReleasedEvent event(key);
						data.EventCallback(event);
						break;
					}
					case GLFW_REPEAT:
					{
						KeyPressedEvent event(key, 1);
						data.EventCallback(event);
						break;
					}
				}
			});

		glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* window, int button, int action, int mods)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				switch (action)
				{
					case GLFW_PRESS:
					{
						MouseButtonPressedEvent event(button);
						data.EventCallback(event);
						break;
					}
					case GLFW_RELEASE:
					{
						MouseButtonReleasedEvent event(button);
						data.EventCallback(event);
						break;
					}
				}
			});

		glfwSetScrollCallback(m_Window, [](GLFWwindow* window, double offsetX, double offsetY)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				
				MouseScrolledEvent event((float)offsetX, (float)offsetY);
				data.EventCallback(event);
			});

		glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double xPos, double yPos)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				MouseMovedEvent event((float)xPos, (float)yPos);
				data.EventCallback(event);
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

		m_Data.VSync = enabled;
	}

	WindowsWindowGL::~WindowsWindowGL()
	{
		Shutdown();
	}
}