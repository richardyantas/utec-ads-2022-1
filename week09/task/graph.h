#ifndef GRAPH_H
#define GRAPH_H

#include <list>
#include <vector>
#include <unordered_map>

using namespace std;

template<typename TV, typename TE>
struct Edge;

template<typename TV, typename TE>
struct Vertex;

template<typename TV, typename TE>
class Graph;

//////////////////////////////////////////////////////

template<typename TV, typename TE>
struct Edge {
    Vertex<TV, TE>* vertexes[2];
    TE weight;
    Edge(){};    
};

template<typename TV, typename TE>
struct Vertex {
    TV data;
    std::list<Edge<TV, TE>*> edges;
    Vertex(){};    
};

template<typename TV, typename TE>
class Graph{
private:        
    //map <id, vertex>
    std::unordered_map<string, Vertex<TV, TE>*>  vertexes;
    
public:
    // bool insertVertex(string id, TV vertex) = 0;   
    // bool createEdge(string id1, string id2, TE w) = 0;    

    bool insertVertex(string id, TV vertex){
        Vertex<TV,TE> *v;
        v = new Vertex<TV,TE>();
        v->data = vertex;
        vertexes[id] = v;
    };

    bool createEdge(string id1, string id2, TE w){        
        Edge<TV,TE> *e = new Edge<TV,TE>();
        e->weight = w;
        e->vertexes[0] = vertexes[id1];
        e->vertexes[1] = vertexes[id2];
        vertexes[id1]->edges.push_back(e);
    };    
    // bool deleteVertex(string id) = 0;     
    // bool deleteEdge(string start, string end) = 0;   
    // TE &operator()(string start, string end)= 0;  
    // float density() = 0;
    // bool isDense(float threshold = 0.5) = 0;
    // bool isConnected()= 0;
    // bool isStronglyConnected() throw();
    // bool empty();
    // void clear()= 0; 
    // void displayVertex(string id)= 0;
    // bool findById(string id) = 0;
    void display(string tag){
        cout << "tag: " << tag << ", id: " << vertexes[tag]->data << endl;
        string delim = "";
        // std::list<Edge<TV, TE>*>::iterator it = 
        for(auto it = vertexes[tag]->edges.begin() ;it != vertexes[tag]->edges.end(); ++it){
            cout << delim << "(" << (*it)->vertexes[1]->data << ", " << (*it)->weight << ")";
            delim = ",";
        }
        cout << endl;
    };
};

#endif