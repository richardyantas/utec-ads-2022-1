#include <iostream>
#include "graph.h"
#include "undirected_graph.h"
using namespace std;

int main(int argc, char *argv[]) {
    // std::cout << "================================================" << std::endl;
    // std::cout << "MENU GRAPH TESTER" << std::endl;
    // std::cout << "================================================" << std::endl;
    
    // Tester::executeExamples();
    // Tester::executeParser();    
    int N,E;
    //cin >> N >> E;
    //Graph<int,int> G;
    UnDirectedGraph<int,int> ug;
    Graph<int,int>* p = &ug;
    
    int weight;
    string id1,id2;
    // for(int i=0;i<N;i++){
    //     cin>>id1;
    //     G.insertVertex(id1,i);
    // }
    // for(int i=0;i<E;i++){        
    //     cin >> id1 >> id2 >> weight;
    //     G.createEdge(id1,id2,weight);
    // }

    p->insertVertex("A",0);
    p->insertVertex("B",1);
    p->insertVertex("C",2);
    p->createEdge("A","B",1);
    p->createEdge("B","C",1);
    p->createEdge("A","C",1);
    
    string ni;
    cin >> ni;
    p->display(ni);

    return EXIT_SUCCESS;
}