// pch
#include "OnyxPch.h"
// Onyx Engine
#include "ImGuiLayer.h"
#include "Onyx/Application.h"
// Vendor
#define IMGUI_IMPL_OPENGL_LOADER_CUSTOM

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <imgui.h>
#include <backends/imgui_impl_glfw.h>
#include <backends/imgui_impl_opengl3.h>
#include <backends/imgui_impl_opengl3.cpp>

namespace Onyx
{

	void ImGuiLayer::OnAttach()
	{
		ImGui::CreateContext();

		ImGui::StyleColorsDark();

		ImGuiIO& io = ImGui::GetIO();
		io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;
		io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;

/////////////////////////////////////////////////////////////
////////////////// TEMP - DEBUG /////////////////////////////
///////// Will be replaced with Onyx keycodes ///////////////
/////////////////////////////////////////////////////////////
		io.KeyMap[ImGuiKey_Tab] = GLFW_KEY_TAB;
		io.KeyMap[ImGuiKey_LeftArrow] = GLFW_KEY_LEFT;
		io.KeyMap[ImGuiKey_RightArrow] = GLFW_KEY_RIGHT;
		io.KeyMap[ImGuiKey_DownArrow] = GLFW_KEY_DOWN;
/////////////////////////////////////////////////////////////

		io.DisplaySize = ImVec2(Application::Get()->GetWindow().GetWidth(), Application::Get()->GetWindow().GetHeight());

		ImGui_ImplOpenGL3_Init("#version 410");
	}

	void ImGuiLayer::OnDetach()
	{

	}

	void ImGuiLayer::OnUpdate()
	{
		ImGui_ImplOpenGL3_NewFrame();
		ImGui::NewFrame();
		
		// Set delta time
		ImGuiIO& io = ImGui::GetIO();

		Application* app = Application::Get();
		io.DisplaySize = ImVec2(app->GetWindow().GetWidth(), app->GetWindow().GetHeight());

		float time = (float)glfwGetTime();
		io.DeltaTime = m_Time > 0.f ? (time - m_Time) : (1.f / 60.f);
		m_Time = time;

		// Show demo window for debugging
		static bool show = true;
		ImGui::ShowDemoWindow(&show);

		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	}

	void ImGuiLayer::OnEvent(Event& e)
	{

	}

	ImGuiLayer::~ImGuiLayer()
	{

	}
}