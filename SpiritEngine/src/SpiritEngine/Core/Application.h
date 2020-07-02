#pragma once

#include "SpiritEngine/Core/Base.h"

#include "SpiritEngine/Core/Window.h"
#include "SpiritEngine/Core/LayerStack.h"
#include "SpiritEngine/Events/Event.h"
#include "SpiritEngine/Events/ApplicationEvent.h"

#include "SpiritEngine/Core/Timestep.h"

#include "SpiritEngine/ImGui/ImGuiLayer.h"

int main(int argc, char** argv);

namespace SpiritEngine {

	class Application
	{
	public:
		Application(const std::string& name = "Spirit Engine App");
		virtual ~Application();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		Window& GetWindow() { return *m_Window; }

		void Close();

		ImGuiLayer* GetImGuiLayer() { return m_ImGuiLayer; }

		static Application& Get() { return *s_Instance; }
	private:
		void Run();
		bool OnWindowClose(WindowCloseEvent& e);
		bool OnWindowResize(WindowResizeEvent& e);
	private:
		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		bool m_Minimized = false;
		LayerStack m_LayerStack;
		float m_LastFrameTime = 0.0f;
	private:
		static Application* s_Instance;
		friend int ::main(int argc, char** argv);
	};

	// To be defined in CLIENT
	Application* CreateApplication();

}