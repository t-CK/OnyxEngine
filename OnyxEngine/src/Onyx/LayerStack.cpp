#include "OnyxPch.h"

#include "LayerStack.h"

namespace Onyx
{
	LayerStack::LayerStack()
	{
		m_LayerInsert = m_Layers.begin();
	}

	void LayerStack::PopLayer(Layer* layer)
	{
		auto it = std::find(m_Layers.begin(), m_Layers.end(), layer);

		if (it != m_Layers.end())
		{
			m_Layers.erase(it);
			m_LayerInsert--;
		}
	}

	void LayerStack::PopOverlay(Layer* overlay)
	{
		auto it = std::find(m_Layers.begin(), m_Layers.end(), overlay);
		if (it != m_Layers.end())
			m_Layers.erase(it);
	}
	LayerStack::~LayerStack()
	{
		for (auto i : m_Layers)
			delete i;
	}
}