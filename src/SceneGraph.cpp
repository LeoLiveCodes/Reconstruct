#include "SceneGraph.h"

SceneGraph::SceneGraph(int V) {
    this->V = V;
    adj = new list<int>[V];
}

void SceneGraph::addEdge(int v, int w) {
    adj[v].push_back(w);
    adj[w].push_back(v);
}
