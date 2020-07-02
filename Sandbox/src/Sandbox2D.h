#pragma once

#include "SpiritEngine.h"

#include "ParticleSystem.h"

class Sandbox2D : public SpiritEngine::Layer
{
public:
	Sandbox2D();
	virtual ~Sandbox2D() = default;

	virtual void OnAttach() override;
	virtual void OnDetach() override;

	void OnUpdate(SpiritEngine::Timestep ts) override;
	virtual void OnImGuiRender() override;
	void OnEvent(SpiritEngine::Event& e) override;
private:
	SpiritEngine::OrthographicCameraController m_CameraController;
	
	// Temp
	SpiritEngine::Ref<SpiritEngine::VertexArray> m_SquareVA;
	SpiritEngine::Ref<SpiritEngine::Shader> m_FlatColorShader;

	SpiritEngine::Ref<SpiritEngine::Texture2D> m_CheckerboardTexture;
	SpiritEngine::Ref<SpiritEngine::Texture2D> m_Spritesheet;

	glm::vec4 m_SquareColor = { 0.2f, 0.3f, 0.8f, 1.0f };

	ParticleSystem m_ParticleSystem;
	ParticleProps m_Particle;
};