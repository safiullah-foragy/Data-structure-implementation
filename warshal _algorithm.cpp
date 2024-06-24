#include <bits/stdc++.h>

using namespace std;


int main() {
    
    int INF=9999;
    vector<vector<int>> graph = {
        {0, 5, INF, 10},
        {INF, 0, 3, INF},
        {INF, INF, 0, 1},
        {INF, INF, INF, 0}
    };

    int V = graph.size();

    
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
     
                    graph[i][j] = min( graph[i][k] + graph[k][j],graph[i][j]);
                
            }
        }
    }

    
    cout << "Shortest path distances:\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
        
                cout << graph[i][j] << " ";
        }
        
        cout << endl;
    }
    

    return 0;
}
