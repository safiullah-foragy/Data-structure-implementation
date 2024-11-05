#include <bits/stdc++.h>


using namespace std;

// Define a pair to store (distance, vertex)
typedef pair<int, int> pii;

void dijkstra(int src, int V, vector<vector<pii>>& adjList) {
    // Initialize distances to all vertices as infinity
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    // Min-heap priority queue (distance, vertex)
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, src});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        // Traverse all adjacent vertices of u
        for (auto& neighbor : adjList[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;

            // If there is a shorter path to v through u
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    // Print the shortest distances from the source
    cout << "Vertex\tDistance from Source " << src << endl;
    for (int i = 0; i < V; ++i) {
        cout << i << "\t" << dist[i] << endl;
    }
}

int main() {
    int V = 5; // Number of vertices
    vector<vector<pii>> adjList(V);

    // Adding edges to the graph (vertex1, vertex2, weight)
    adjList[0].push_back({1, 2});
    adjList[0].push_back({3, 1});
    adjList[1].push_back({0, 2});
    adjList[1].push_back({2, 4});
    adjList[2].push_back({1, 4});
    adjList[2].push_back({3, 5});
    adjList[3].push_back({0, 1});
    adjList[3].push_back({2, 5});
    adjList[3].push_back({4, 3});
    adjList[4].push_back({3, 3});

    int src = 0; // Starting vertex
    dijkstra(src, V, adjList);

    return 0;
}
