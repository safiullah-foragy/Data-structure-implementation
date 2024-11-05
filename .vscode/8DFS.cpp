#include <iostream>
#include <stack>

using namespace std;

const int V = 4;
int adjMatrix[V][V] = {0};

void addEdge(int src, int dest)
{
    adjMatrix[src][dest] = 1; 
    adjMatrix[dest][src] = 1; 
}

void deleteEdge(int src, int dest)
{
    adjMatrix[src][dest] = 0;
    adjMatrix[dest][src] = 0;
}

void DFS(int start)
{
    bool visited[V] = {false};
    stack<int> s;

    visited[start] = true;
    s.push(start);

    while (!s.empty())
    {
        int currVertex = s.top();
        cout << "Visited " << currVertex << endl;
        s.pop();

        for (int i = 0; i < V; i++)
        {
            if (adjMatrix[currVertex][i] == 1 && !visited[i])
            {
                visited[i] = true;
                s.push(i);
            }
        }
    }
}

int main()
{
    // Adding edges
    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 2);
    addEdge(2, 3);

    cout << "DFS starting from vertex 2:\n";
    DFS(2);

    // Deleting an edge
    cout << "\nDeleting edge (1, 2) and performing DFS again:\n";
    deleteEdge(1, 2);
    DFS(2);

    // Adding the edge back
    cout << "\nInserting edge (1, 2) again and performing DFS:\n";
    addEdge(1, 2);
    DFS(2);

    return 0;
}
