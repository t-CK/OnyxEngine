#pragma once

// Onyx Engine
#include "Onyx/Window.h"
// Vendors
#include <GLFW/glfw3.h>


namespace Onyx
{
	class ONYX_API WindowsWindowGL :
		public Window
	{
	public:
		WindowsWindowGL(const  WindowProps& props);

		void OnUpdate() override;

		////////////////// Window size getters ////////////////////////

		inline unsigned int GetWidth() const override { return m_Data.m_Width; }
		inline unsigned int GetHeight() const override { return m_Data.m_Height; }

		inline void SetEventCallback(const EventCallbackFn& callback) override { m_Data.m_EventCallback = callback; }

		///////////////////// V-sync /////////////////////////////////

		void SetVSync(bool enabled) override;
		inline bool IsVSync() const override { return m_Data.m_VSync; }
		/////////////////////////////////////////////////////////////

		inline void* GetNativeWindow() const override { return (void*)m_Window; }


		virtual ~WindowsWindowGL();

	private:
		virtual void Init(const WindowProps& props);
		virtual void Shutdown();

	private:
		GLFWwindow* m_Window;

		struct WindowData
		{
			std::string m_Title; unsigned int m_Width, m_Height;
			bool m_VSync;

			EventCallbackFn m_EventCallback;
		};
		WindowData m_Data;
	};
}