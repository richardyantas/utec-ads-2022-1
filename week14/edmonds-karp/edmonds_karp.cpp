#include <iostream>
#include <queue>
#include <vector>
#define INF 2 << 16
using namespace std;

int test_cases;
int N, E, a, b, c;

// int n;
vector<vector<int>> capacity;
vector<vector<int>> adj;

int bfs(int s, int t, vector<int> &parent) {
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    queue<pair<int, int>> q;
    q.push({s, INF});

    while (!q.empty()) {
        int cur = q.front().first;
        int flow = q.front().second;
        q.pop();

        for (int next : adj[cur]) {
            if (parent[next] == -1 && capacity[cur][next]) {
                parent[next] = cur;
                int new_flow = min(flow, capacity[cur][next]);
                if (next == t)
                    return new_flow;
                q.push({next, new_flow});
            }
        }
    }
    return 0;
}

int maxflow(int s, int t) {
    int flow = 0;
    vector<int> parent(N);
    int new_flow;

    while (new_flow = bfs(s, t, parent)) {
        flow += new_flow;
        int cur = t;
        while (cur != s) {
            int prev = parent[cur];
            capacity[prev][cur] -= new_flow;
            capacity[cur][prev] += new_flow;
            cur = prev;
        }
    }

    return flow;
}

int main() {
    cin >> test_cases;
    while (test_cases--) {
        cin >> N >> E;
        cout << "N: " << N << ", E: " << E << endl;
        adj.resize(N);

        capacity.resize(N);
        for (int i = 0; i < N; i++) {
            capacity[i].resize(N);
        }

        while (E--) {
            // 0 <= a,b <= N
            cin >> a >> b >> c;
            adj[a].push_back(b);
            capacity[a][b] = c;
            cout << a << " " << b << " " << c << endl;
        }
        cout << "max flow: " << maxflow(0, N - 1) << endl;

        adj.clear();
    }

    return 0;
}