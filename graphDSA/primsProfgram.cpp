
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void primMST(const vector<vector<int>> &graph)
{
    int n = graph.size();
    vector<bool> inMST(n, false);
    vector<int> key(n, INT_MAX);
    vector<int> parent(n, -1);

    key[0] = 0; // Start with the first vertex

    cout << "Minimum Spanning Tree (Prim's Algorithm):" << endl;

    for (int count = 0; count < n - 1; ++count)
    {
        int u = -1;

        // Find the vertex with the minimum key value that is not yet in the MST
        for (int i = 0; i < n; ++i)
        {
            if (!inMST[i] && (u == -1 || key[i] < key[u]))
            {
                u = i;
            }
        }

        inMST[u] = true;

        // Update key values and parent for adjacent vertices of the picked vertex
        for (int v = 0; v < n; ++v)
        {
            if (graph[u][v] && !inMST[v] && graph[u][v] < key[v])
            {
                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    // Print the MST edges
    for (int i = 1; i < n; ++i)
    {
        cout << "Edge: (" << parent[i] << "-" << i << ") with weight " << key[i] << endl;
    }
}

int main()
{
    // Example graph represented using an adjacency matrix with weighted edges
    vector<vector<int>> graph = {
        {0, 2, 0, 8, 0},
        {2, 0, 3, 5, 1},
        {0, 3, 0, 0, 7},
        {8, 5, 0, 0, 4},
        {0, 1, 7, 4, 0}};

    // Starting Prim's algorithm
    primMST(graph);

    return 0;
}
