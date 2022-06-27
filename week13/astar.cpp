#include <cmath>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define INF 2 << 28

struct Node {
    int id;
    int x, y;
    Node(int id = 0, int x = 0, int y = 0) {
        this->id = id;
        this->x = x;
        this->y = y;
    }
};

const int N = 6;
vector<pair<Node *, int>> adj[N];
vector<Node *> nodes(N);

void addEdge(int id1, int id2, int w) {
    adj[id1].push_back(make_pair(nodes[id2], w));
    adj[id2].push_back(make_pair(nodes[id1], w));
}

int euclidean(int id1, int id2) {
    int xo = nodes[id1]->x;
    int xf = nodes[id2]->x;
    int yo = nodes[id1]->y;
    int yf = nodes[id2]->y;

    return sqrt(pow(xf - xo, 2) + pow(yf - yo, 2));
}

int dijkstraToStar() {

    /*

                           *(3)---1---*(4)
                          /  |           |
                      4 /    1           1
                    /        |           |
                 /           |           |
    *(0)-1-*(1)----3------*(2)--1-----*(5)

    */

    nodes[0] = new Node(0, 0, 0);
    nodes[1] = new Node(1, 3, 0);
    nodes[2] = new Node(2, 5, 0);
    nodes[3] = new Node(3, 5, 2);
    nodes[4] = new Node(4, 7, 2);
    nodes[5] = new Node(5, 7, 0);

    addEdge(0, 1, 1);
    addEdge(1, 2, 3);
    addEdge(1, 3, 4);
    addEdge(2, 3, 1);
    addEdge(3, 4, 1);
    addEdge(4, 5, 1);
    addEdge(5, 2, 1);

    // node 0 -> node 4
    priority_queue<pair<int, int>> q;
    vector<int> distance;
    vector<bool> processed;
    distance.assign(N, INF);
    processed.assign(N, false);

    // for (int i = 0; i < N; i++)
    //     distance[i] = INF;

    int start = 0;
    int obj = 4;
    distance[start] = 0;
    q.push({-distance[start], start});

    while (!q.empty()) {
        int a = q.top().second;
        q.pop();
        if (processed[a])
            continue;
        processed[a] = true;
        for (auto u : adj[a]) {
            int b = u.first->id, w = u.second;
            int g = euclidean(b, obj);

            if (distance[a] + w < distance[b]) {
                distance[b] = distance[a] + w;
                q.push({-distance[b] + g, b});
            }

            // if (distance[a] + w + g < mind) {
            // int mind = INF;
            //     mind = distance[a] + w + g;
            //     distance[b] = distance[a] + w;
            //     q.push({-distance[b], b});
            // }
        }
    }

    for (int i = 0; i < distance.size(); i++) {
        cout << distance[i] << " ";
    }
    cout << endl;
    return distance[obj];
}

int main() {
    cout << dijkstraToStar() << endl;
    return 0;
}