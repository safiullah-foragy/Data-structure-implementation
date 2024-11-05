#include <iostream>
using namespace std;

#define M 4 

void printMatrix(int matrix[M][M]) {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}


void warshallAlgorithm(int (&A)[M][M]) {
    
    for (int k = 0; k < M; k++) {
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < M; j++) {
                A[i][j] = A[i][j] || (A[i][k] && A[k][j]);
            }
        }
    }
}

int main() {
   
    int graph[M][M] = {
        {0, 0, 0, 1},
        {1, 0, 1, 1},
        {1, 0, 0, 1},
        {0, 0, 1, 0}
    };

    cout << "Original Adjacency Matrix:" << endl;
    printMatrix(graph);

    
    warshallAlgorithm(graph);

    cout << "Transitive Closure Matrix :" << endl;
    printMatrix(graph);

    return 0;
}
