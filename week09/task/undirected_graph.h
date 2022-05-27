#ifndef UNDIRECTEDGRAPH_H
#define UNDIRECTEDGRAPH_H

#include "graph.h"

template<typename TV, typename TE>
class UnDirectedGraph : public Graph<TV, TE>{

    bool insertVertex(string id, TV vertex){
        Vertex<TV,TE> *v;
        v = new Vertex<TV,TE>();
        v->data = vertex;
        vertexes[id] = v;
    };

    bool createEdge(string id1, string id2, TE w){        
        Edge<TV,TE> *e1 = new Edge<TV,TE>(), *e2 = new Edge<TV,TE>();
        e1->weight = w;
        e1->vertexes[0] = vertexes[id1];
        e1->vertexes[1] = vertexes[id2];
        e2->weight = w;
        e2->vertexes[0] = vertexes[id2];
        e2->vertexes[1] = vertexes[id1];
        vertexes[id1]->edges.push_back(e1);
        vertexes[id2]->edges.push_back(e2);
        
        // delete [] p;
        // delete [] t;
    };
        
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