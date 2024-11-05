#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void bellmanFord(int V, int E, vector<vector<int>>& edges, int source) {
    vector<int> distance(V, INT_MAX);
    distance[source] = 0;

    // Relax all edges V - 1 times
    for (int i = 0; i < V - 1; i++) {
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int weight = edge[2];
            if (distance[u] != INT_MAX && distance[u] + weight < distance[v]) {
                distance[v] = distance[u] + weight;
            }
        }
    }

    // Check for negative-weight cycles
    for (auto& edge : edges) {
        int u = edge[0];
        int v = edge[1];
        int weight = edge[2];
        if (distance[u] != INT_MAX && distance[u] + weight < distance[v]) {
            cout << "Graph contains negative weight cycle\n";
            return;
        }
    }

    // Output distances from the source
    cout << "Vertex   Distance from Source\n";
    for (int i = 0; i < V; i++) {
        cout << i << "\t\t" << (distance[i] == INT_MAX ? "INF" : to_string(distance[i])) << "\n";
    }
}

int main() {
    int V = 5; // Number of vertices
    int E = 8; // Number of edges

    vector<vector<int>> edges = {
        {0, 1, -1}, {0, 2, 4}, {1, 2, 3}, {1, 3, 2},
        {1, 4, 2}, {3, 2, 5}, {3, 1, 1}, {4, 3, -3}
    };

    int source = 0;
    bellmanFord(V, E, edges, source);

    return 0;
}
