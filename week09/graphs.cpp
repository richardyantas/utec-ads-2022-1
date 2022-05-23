#include<iostream>
#include<vector>
#include<utility>
#include<queue>
using namespace std;

void prim(vector<vector<int>> G){
  int inode = 0;
  priority_queue<pair<int,int>> pq;
  for(int i=0;i<G[inode].size();i++){
    pq.push(make_pair(-G[inode][i],i));
  }  
  while(!pq.empty()){
    int node = pq.top();
    pq.pop();
    
  }


  // for(int i=0; i<G[inode].size();i++){

  // }

}


void kruskal(){

}

vector<vector<int>> build_graph(bool isdirected){
  int V = 6;
  vector<pair<int,int>> edges = {{1,3},{1,2},{1,6},{2,3},{6,3},{6,5},{5,4},{4,2}};
  vector<vector<int>> G(V);  
  int E = 8;
  for(int i=0;i<E;i++){
    int a,b;    
    a = edges[i].first-1;
    b = edges[i].second-1;
    bool bfound = false;
    for(int j=0;j<G[a].size();j++){
      if(G[a][j] == b)bfound = true;
    }
    if(!bfound){      
      if(isdirected){
        G[a].push_back(b);
      }
      else{        
        G[a].push_back(b);
        G[b].push_back(a);
      }
    }
  }
  return G;
}
void print_graph(const vector<vector<int>> &G){  
  for(int i=0;i<G.size();i++){
    cout << "node " << i << ": ";
    for(int j=0;j<G[i].size();j++){
      cout << G[i][j] << ",";
    }
    cout << endl;
  }
}

int main(){
  vector<vector<int>> G;
  G = build_graph(false);
  print_graph(G);
  return 0;
}