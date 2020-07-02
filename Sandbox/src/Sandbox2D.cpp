#include "Sandbox2D.h"
#include <imgui/imgui.h>

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

Sandbox2D::Sandbox2D()
	: Layer("Sandbox2D"), m_CameraController(1280.0f / 720.0f), m_SquareColor({ 0.2f, 0.3f, 0.8f, 1.0f })
{
}

void Sandbox2D::OnAttach()
{
	SPIRIT_PROFILE_FUNCTION();

	m_CheckerboardTexture = SpiritEngine::Texture2D::Create("assets/textures/Checkerboard.png");
	m_CheckerboardTexture = SpiritEngine::Texture2D::Create("assets/game/textures/RPGpack_sheet_2X.png");

	m_Particle.ColorBegin = { 254 / 255.0f, 212 / 255.0f, 123 / 255.0f, 1.0f };
	m_Particle.ColorEnd = { 254 / 255.0f, 109 / 255.0f, 41 / 255.0f, 1.0f };
	m_Particle.SizeBegin = 0.5f, m_Particle.SizeVariation = 0.3f, m_Particle.SizeEnd = 0.0f;
	m_Particle.LifeTime = 5.0f;
	m_Particle.Velocity = { 0.0f, 0.0f };
	m_Particle.VelocityVariation = { 3.0f, 1.0f };
	m_Particle.Position = { 0.0f, 0.0f };
}

void Sandbox2D::OnDetach()
{
	SPIRIT_PROFILE_FUNCTION();
}

void Sandbox2D::OnUpdate(SpiritEngine::Timestep ts)
{
	SPIRIT_PROFILE_FUNCTION();

	// Update
	m_CameraController.OnUpdate(ts);

	// Render
	SpiritEngine::Renderer2D::ResetStats();
	{
		SPIRIT_PROFILE_SCOPE("Renderer Prep");
		SpiritEngine::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
		SpiritEngine::RenderCommand::Clear();
	}

#if 1
	{
		static float rotation = 0.0f;
		rotation += ts * 50.0f;

		SPIRIT_PROFILE_SCOPE("Renderer Draw");
		SpiritEngine::Renderer2D::BeginScene(m_CameraController.GetCamera());
		SpiritEngine::Renderer2D::DrawRotatedQuad({ 1.0f, 0.0f }, { 0.8f, 0.8f }, glm::radians(-45.0f), { 0.8f, 0.2f, 0.3f, 1.0f });
		SpiritEngine::Renderer2D::DrawQuad({ -1.0f, 0.0f }, { 0.8f, 0.8f }, { 0.8f, 0.2f, 0.3f, 1.0f });
		SpiritEngine::Renderer2D::DrawQuad({ 0.5f, -0.5f }, { 0.5f, 0.75f }, m_SquareColor);
		SpiritEngine::Renderer2D::DrawQuad({ 0.0f, 0.0f, -0.1f }, { 20.0f, 20.0f }, m_CheckerboardTexture, 10.0f);
		SpiritEngine::Renderer2D::DrawRotatedQuad({ -2.0f, 0.0f, 0.0f }, { 1.0f, 1.0f }, glm::radians(rotation), m_CheckerboardTexture, 20.0f);
		SpiritEngine::Renderer2D::EndScene();

		SpiritEngine::Renderer2D::BeginScene(m_CameraController.GetCamera());
		for (float y = -5.0f; y < 5.0f; y += 0.5f)
		{
			for (float x = -5.0f; x < 5.0f; x += 0.5f)
			{
				glm::vec4 color = { (x + 5.0f) / 10.0f, 0.4f, (y + 5.0f) / 10.0f, 0.7f };
				SpiritEngine::Renderer2D::DrawQuad({ x, y }, { 0.45f, 0.45f }, color);
			}
		}
		SpiritEngine::Renderer2D::EndScene();
	}
#endif

	if (SpiritEngine::Input::IsMouseButtonPressed(SPIRIT_MOUSE_BUTTON_LEFT))
	{
		auto [x, y] = SpiritEngine::Input::GetMousePosition();
		auto width = SpiritEngine::Application::Get().GetWindow().GetWidth();
		auto height = SpiritEngine::Application::Get().GetWindow().GetHeight();

		auto bounds = m_CameraController.GetBounds();
		auto pos = m_CameraController.GetCamera().GetPosition();
		x = (x / width) * bounds.GetWidth() - bounds.GetWidth() * 0.5f;
		y = bounds.GetHeight() * 0.5f - (y / height) * bounds.GetHeight();
		m_Particle.Position = { x + pos.x, y + pos.y };
		for (int i = 0; i < 5; i++)
			m_ParticleSystem.Emit(m_Particle);
	}

#if 0
	SpiritEngine::Renderer2D::BeginScene(m_CameraController.GetCamera());
	SpiritEngine::Renderer2D::DrawQuad({ 0.0f, 0.0f, 0.0f }, { 20.0f, 20.0f }, m_Spritesheet);
	SpiritEngine::Renderer2D::EndScene();
#endif


	m_ParticleSystem.OnUpdate(ts);
	m_ParticleSystem.OnRender(m_CameraController.GetCamera());
}

void Sandbox2D::OnImGuiRender()
{
	SPIRIT_PROFILE_FUNCTION();

	ImGui::Begin("Settings");

	auto stats = SpiritEngine::Renderer2D::GetStats();
	ImGui::Text("Renderer2D Stats:");
	ImGui::Text("Draw Calls: %d", stats.DrawCalls);
	ImGui::Text("Quads: %d", stats.QuadCount);
	ImGui::Text("Vertices: %d", stats.GetTotalVertexCount());
	ImGui::Text("Indices: %d", stats.GetTotalIndexCount());

	ImGui::ColorEdit4("Square Color", glm::value_ptr(m_SquareColor));
	ImGui::End();

	static bool show = true;
	ImGui::ShowDemoWindow(&show);
}

void Sandbox2D::OnEvent(SpiritEngine::Event& e)
{
	m_CameraController.OnEvent(e);
}