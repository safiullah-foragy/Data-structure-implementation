#include <iostream>
using namespace std;

#define M 4             
#define INF 1000000     

void printMatrix(int matrix[M][M]) {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            if (matrix[i][j] == INF)
                cout << "INF ";
            else
                cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}


void floydWarshall(int (&graph)[M][M]) {
   

    for (int k = 0; k < M; k++) {
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < M; j++) {
               
                    graph[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    cout << "Shortest Path Matrix:" << endl;
    printMatrix(dist);
}

int main() {
    
    int graph[M][M] = {
        {0, 3, 0, 7},
        {8, 0, 2, 0},
        {5, 0, 0, 1},
        {2, 0, 0, 0}
    };

    for(int i=0;i<M;i++)
    {
      for(int j=0;j<M;j++)
      {

if(graph[i][j]==0){graph[i][j]=INF;}

      }
    }

    floydWarshall(graph);

    return 0;
}
