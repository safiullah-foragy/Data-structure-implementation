#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent an edge
struct Edge {
    int src, dest, weight;
};

// Comparator to sort edges based on weight
bool compareEdges(const Edge& a, const Edge& b) {
    return a.weight < b.weight;
}

// Union-Find functions
int findParent(int v, vector<int>& parent) {
    if (parent[v] != v) {
        parent[v] = findParent(parent[v], parent);  // Path compression
    }
    return parent[v];
}

void unionSets(int u, int v, vector<int>& parent, vector<int>& rank) {
    u = findParent(u, parent);
    v = findParent(v, parent);

    if (rank[u] < rank[v]) {
        parent[u] = v;
    } else if (rank[u] > rank[v]) {
        parent[v] = u;
    } else {
        parent[v] = u;
        rank[u]++;
    }
}

void kruskalMST(int vertices, const vector<Edge>& edges) {
    vector<Edge> mst;  // To store the result MST

    // Step 1: Sort all edges by weight
    vector<Edge> sortedEdges = edges;
    sort(sortedEdges.begin(), sortedEdges.end(), compareEdges);

    // Initialize parent and rank for Union-Find
    vector<int> parent(vertices);
    vector<int> rank(vertices, 0);

    for (int i = 0; i < vertices; i++) {
        parent[i] = i;
    }

    // Step 2: Pick the smallest edge and add to MST if no cycle is formed
    for (const auto& edge : sortedEdges) {
        int uParent = findParent(edge.src, parent);
        int vParent = findParent(edge.dest, parent);

        if (uParent != vParent) {  // If adding this edge doesn't form a cycle
            mst.push_back(edge);   // Include it in MST
            unionSets(uParent, vParent, parent, rank);  // Union the sets
        }
    }

    // Print the MST
    cout << "Edges in the Minimum Spanning Tree:" << endl;
    int mstWeight = 0;
    for (const auto& edge : mst) {
        cout << edge.src << " -- " << edge.dest << " == " << edge.weight << endl;
        mstWeight += edge.weight;
    }
    cout << "Total weight of MST: " << mstWeight << endl;
}

int main() {
    int vertices = 4;  // Number of vertices in the graph
    vector<Edge> edges = { {0, 1, 10}, {0, 2, 6}, {0, 3, 5}, {1, 3, 15}, {2, 3, 4} };

    kruskalMST(vertices, edges);

    return 0;
}
