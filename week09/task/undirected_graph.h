#ifndef UNDIRECTEDGRAPH_H
#define UNDIRECTEDGRAPH_H
#include "graph.h"
#include <cstring>
#include <iostream>

// using namespace std;

template <typename TV, typename TE>
class UnDirectedGraph : public Graph<TV, TE> {
  public:
    bool insertVertex(string id, TV vertex) {
        Vertex<TV, TE> *v;
        v = new Vertex<TV, TE>();
        v->data = vertex;
        v->tag = id;
        Graph<TV, TE>::vertexes[id] = v;
    };

    bool createEdge(string id1, string id2, TE w) {
        Edge<TV, TE> *e1 = new Edge<TV, TE>(), *e2 = new Edge<TV, TE>();
        e1->weight = w;
        e1->vertexes[0] = Graph<TV, TE>::vertexes[id1];
        e1->vertexes[1] = Graph<TV, TE>::vertexes[id2];
        e2->weight = w;
        e2->vertexes[0] = Graph<TV, TE>::vertexes[id2];
        e2->vertexes[1] = Graph<TV, TE>::vertexes[id1];
        Graph<TV, TE>::vertexes[id1]->edges.push_back(e1);
        Graph<TV, TE>::vertexes[id2]->edges.push_back(e2);

        // delete [] p;
        // delete [] t;
    };

    void display(string tag) {
        cout << "tag: " << tag << ", id: " << Graph<TV, TE>::vertexes[tag]->data
             << endl;
        string delim = "";
        // std::list<Edge<TV, TE>*>::iterator it =
        for (auto it = Graph<TV, TE>::vertexes[tag]->edges.begin();
             it != Graph<TV, TE>::vertexes[tag]->edges.end(); ++it) {
            cout << delim << "(" << (*it)->vertexes[1]->data << ", "
                 << (*it)->weight << ")";
            delim = ",";
        }
        cout << endl;
    };

    void prim(string tag) {
        tag = "A";
        priority_queue<pair<int, int>> pq; // check >> problem clang
        pq.push(make_pair(0, tag);
        Graph<TV, TE>::vertexes[tag]->visited = true;
        vector<Edge<TV,TE>> tree;
        while (!pq.empty) {
            pair<int, int> par = q.top();
            q.pop();
            tag = par.second;
            for (auto it = Graph<TV, TE>::vertexes[tag]->edges.begin();
                 it != Graph<TV, TE>::vertexes[tag]->edges.end(); ++it) {
                if (!(*it)->vertexes[1]->visited) {
                    pq.push(
                    make_pair(-(*it)->weight, (*it)->vertexes[1]->tag);
                    (*it)->vertexes[1]->visited = true;
                    tree.push_back((*it));
                }
            }
        }
    };

        // template <typename TV, typename TE>
        // void UnDirectedGraph<TV, TE>::prim(string tag) {
        //     tag = "A";
        //     priority_queue<pair<int, int>> pq; // check >> problem clang
        //     // auto it = Graph<TV, TE>::vertexes[tag];
        //     pq.push(make_pair(Graph<TV, TE>::vertexes[tag]->data, 0));

        //     for (auto it = Graph<TV, TE>::vertexes[tag]->edges.begin();
        //          it != Graph<TV, TE>::vertexes[tag]->edges.end(); ++it) {

        //         pq.push(make_pair((*it)->vertexes[1]->,
        //         (*it)->vertexes[1]->data));

        //         // cout << delim << "(" << (*it)->vertexes[1]->data << ", "
        //         //      << (*it)->weight << ")";
        //         // delim = ",";
        //     }
        // }

#endif