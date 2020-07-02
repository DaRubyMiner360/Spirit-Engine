#include <SpiritEngine.h>
#include <SpiritEngine/Core/EntryPoint.h>

#include "EditorLayer.h"

namespace SpiritEngine {

	class SpiritEditor : public Application
	{
	public:
		SpiritEditor()
			: Application("Spirit Engine")
		{
			PushLayer(new EditorLayer());
		}

		~SpiritEditor()
		{
		}
	};

	Application* CreateApplication()
	{
		return new SpiritEditor();
	}

}