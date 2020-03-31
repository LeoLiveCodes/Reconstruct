#ifndef SCENE_GRAPH_H
#define SCENE_GRAPH_H 

#include<iostream> 
#include <list> 
#include <limits.h> 

using namespace std; 
  
class SceneGraph 
{ 
    int V;    // No. of vertices 
    list<int> *adj;    // Pointer to an array containing adjacency lists 
    
public: 
    SceneGraph(int V); 
    void addEdge(int v, int w);   // to add an edge to graph 

}; 

#endif
