#include "SceneGraph.h"

SceneGraph::SceneGraph()
{
}
void SceneGraph::Update() {
	for (auto item : children) {
		item->Update();
	}
}

SceneGraph::~SceneGraph()
{
}
