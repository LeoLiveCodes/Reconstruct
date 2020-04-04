#include "SceneGraph.h"

SceneGraph::SceneGraph(int V) {
    this->V = V;
    adj = new list<int>[V];
}

void SceneGraph::addEdge(int v, int w) {
    adj[v].push_back(w);
    adj[w].push_back(v);
}

void SceneGraph::GetNodesWithMatches(vector<int>& img_indices) const {
    list<int> *p = adj;
    for (int i = 0; i < V; ++i) {
        if (!p->empty()) {
            img_indices.push_back(i);
        }
        p++;
    }
}

list<int> SceneGraph::GetImageMatches(int idx) const {
    return adj[idx];
}
