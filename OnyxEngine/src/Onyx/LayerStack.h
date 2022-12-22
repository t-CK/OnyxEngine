#pragma once

// Onyx Engine
#include "Layer.h"
// C++ standard libraries
#include <vector>

namespace Onyx
{
	class ONYX_API LayerStack
	{
	public:
		LayerStack();

		inline void OnLayerInsert(Layer* layer) { m_LayerInsert = m_Layers.emplace(m_LayerInsert, layer); }
		inline void OnOverlayPush(Layer* overlay) { m_Layers.emplace_back(overlay); }
		void PopLayer(Layer* layer);
		void PopOverlay(Layer* layer);

		std::vector<Layer*>::iterator begin() { return m_Layers.begin(); }
		std::vector<Layer*>::iterator end() { return m_Layers.end(); }

		~LayerStack();
	private:
		std::vector<Layer*> m_Layers;
		std::vector<Layer*>::iterator m_LayerInsert;

	};
}