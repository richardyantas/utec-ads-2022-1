#ifndef GRAPH_H
#define GRAPH_H

#include <list>
#include <unordered_map>
#include <vector>

using namespace std;

template <typename TV, typename TE> struct Edge;

template <typename TV, typename TE> struct Vertex;

template <typename TV, typename TE> class Graph;

//////////////////////////////////////////////////////

template <typename TV, typename TE> struct Edge {
    Vertex<TV, TE> *vertexes[2];
    TE weight;
    Edge(){};
};

template <typename TV, typename TE> struct Vertex {
    // visited
    bool visited = false;
    bool taken = false;
    //
    string tag;
    TV data;
    std::list<Edge<TV, TE> *> edges;
    Vertex(){};
};

template <typename TV, typename TE> class Graph {
  private:
  protected:
    // map <id, vertex>
    std::unordered_map<string, Vertex<TV, TE> *> vertexes;

  public:
    virtual bool insertVertex(string id, TV vertex) = 0;
    virtual bool createEdge(string id1, string id2, TE w) = 0;
    // bool deleteVertex(string id) = 0;
    // bool deleteEdge(string start, string end) = 0;
    // TE &operator()(string start, string end)= 0;
    // float density() = 0;
    // bool isDense(float threshold = 0.5) = 0;
    // bool empty();
    // void clear()= 0;
    // void displayVertex(string id)= 0;
    // bool findById(string id) = 0;

    // bool isConnected()= 0;
    // bool isStronglyConnected() throw();
    virtual void display(string tag) = 0;

    virtual void prim(string tag) = 0;
    // virtual void kruskal(string tag) = 0;
    // virtual void dijkstra(string tag) = 0;
    // virtual void astar(string tag) = 0;
};

#endif