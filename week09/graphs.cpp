#include <iostream>
#include <queue>
#include <stack>
#include <utility>
#include <vector>
using namespace std;

const int V = 7;
const int E = 8;
vector<pair<int, int>> edges = {{1, 3}, {1, 2}, {1, 6}, {2, 3},
                                {6, 3}, {6, 5}, {5, 4}, {4, 2}};
vector<vector<int>> G(V);

vector<vector<int>> build_graph(bool isdirected) {
    for (int i = 0; i < E; i++) {
        int a, b;
        a = edges[i].first;
        b = edges[i].second;
        bool bfound = false;
        for (int j = 0; j < G[a].size(); j++) {
            if (G[a][j] == b)
                bfound = true;
        }
        if (!bfound) {
            if (isdirected) {
                G[a].push_back(b);
            } else {
                G[a].push_back(b);
                G[b].push_back(a);
            }
        }
    }
    return G;
}

// bool visited[V];
vector<bool> visited(V);
void dfs(int s) {
    if (visited[s])
        return;
    visited[s] = true;
    // process node s
    for (auto u : G[s]) {
        dfs(u);
    }
}

bool isconnected() {
    int cont = 0;
    dfs(0);
    for (int i = 0; i < V; i++) {
        if (visited[i]) {
            cont++;
        }
    }
    return cont < V ? false : true;
}

vector<int> ans(V);
bool isCycleFound(int s) {
    visited.assign(V, false);
    // memset(V, 0, sizeof(V));
    stack<int> st;
    st.push(s);
    visited[s] = true;
    while (!st.empty()) {
        int s = st.top();
        st.pop();
        for (auto u : G[s]) {
            ans[u] = s;
            if (visited[u] && ans[s] != u) {
                return true;
            }
            st.push(u);
            visited[u] = true;
        }
    }
    return false;
}

void print_graph(const vector<vector<int>> &G) {
    for (int i = 0; i < G.size(); i++) {
        cout << "node " << i << ": ";
        for (int j = 0; j < G[i].size(); j++) {
            cout << G[i][j] << ",";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> G;
    G = build_graph(false);
    if (isconnected()) {
        cout << "El grafo esta conectado" << endl;
    } else {
        cout << "El grafo esta desconectado" << endl;
    }

    if (isCycleFound(0)) {
        cout << "A cycle is found" << endl;
    } else {
        cout << "No cycle is found" << endl;
    }

    print_graph(G);
    return 0;
}