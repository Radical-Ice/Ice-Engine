#include "SceneGraph.h"

SceneGraph::SceneGraph()
{
}
void SceneGraph::Update(sf::RenderWindow & renderWindow) {
	for (auto item : children) {

		item->Update(renderWindow);
	}
}

SceneGraph::~SceneGraph()
{
}
