#include <iostream>
#include "graph.h"
using namespace std;

int main(int argc, char *argv[]) {
    // std::cout << "================================================" << std::endl;
    // std::cout << "MENU GRAPH TESTER" << std::endl;
    // std::cout << "================================================" << std::endl;
    
    // Tester::executeExamples();
    // Tester::executeParser();    
    int N,E;
    cin >> N >> E;
    Graph<int,int> G;
    
    int weight;
    string id1,id2;
    for(int i=0;i<N;i++){
        cin>>id1;
        G.insertVertex(id1,i);
    }

    for(int i=0;i<E;i++){        
        cin >> id1 >> id2 >> weight;
        G.createEdge(id1,id2,weight);
    }
    
    string ni="B";
    G.display(ni);

    return EXIT_SUCCESS;
}