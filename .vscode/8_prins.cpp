#include <iostream>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

// Define a structure for edges in the priority queue
typedef pair<int, int> Edge; // (weight, destination)

// Prim's algorithm function
void primMST(int V, vector<vector<int>>& graph) {
    // Array to store the minimum edge weight to reach a vertex
    vector<int> key(V, INT_MAX);
    // Array to keep track of vertices included in the MST
    vector<bool> inMST(V, false);
    // Array to store the parent of each vertex in the MST
    vector<int> parent(V, -1);

    // Priority queue to pick minimum weight edge at each step
    priority_queue<Edge, vector<Edge>, greater<Edge>> pq;

    // Start from the first vertex (0)
    key[0] = 0;
    pq.push({0, 0});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        // Mark the current vertex as included in the MST
        inMST[u] = true;

        // Traverse all adjacent vertices of u
        for (int v = 0; v < V; v++) {
            // Check if there's an edge, and if v is not yet in MST and weight is smaller than current key
            if (graph[u][v] && !inMST[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
                pq.push({key[v], v});
                parent[v] = u;
            }
        }
    }

    // Display the MST edges
    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++) {
        cout << parent[i] << " - " << i << "\t" << graph[i][parent[i]] << endl;
    }
}

int main() {
    int V = 5;  // Number of vertices in the graph
    vector<vector<int>> graph = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    primMST(V, graph);

    return 0;
}
