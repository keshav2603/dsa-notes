#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Structure to represent an edge in the graph
struct Edge
{
    int src, dest, weight;

    // Comparison operator for sorting edges based on weight
    bool operator<(const Edge &other) const
    {
        return weight < other.weight;
    }
};

class KruskalMST
{
public:
    KruskalMST(int vertices) : V(vertices) {}

    // Function to add an edge to the graph
    void addEdge(int src, int dest, int weight)
    {
        edges.push_back({src, dest, weight});
    }

    // Function to find the parent of a set
    int find(int vertex, vector<int> &parent);

    // Function to perform union of two sets
    void unionSets(int x, int y, vector<int> &parent, vector<int> &rank);

    // Function to run Kruskal's algorithm and print the MST
    void runKruskal();

private:
    int V;              // Number of vertices in the graph
    vector<Edge> edges; // Vector to store the edges of the graph
};

int KruskalMST::find(int vertex, vector<int> &parent)
{
    // Find the representative of the set to which vertex belongs
    if (parent[vertex] == -1)
        return vertex;
    return find(parent[vertex], parent);
}

void KruskalMST::unionSets(int x, int y, vector<int> &parent, vector<int> &rank)
{
    // Perform union by rank
    int rootX = find(x, parent);
    int rootY = find(y, parent);

    if (rootX != rootY)
    {
        if (rank[rootX] < rank[rootY])
            parent[rootX] = rootY;
        else if (rank[rootX] > rank[rootY])
            parent[rootY] = rootX;
        else
        {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }
}

void KruskalMST::runKruskal()
{
    // Sort the edges based on their weights
    sort(edges.begin(), edges.end());

    vector<int> parent(V, -1); // Initialize parent array for union-find
    vector<int> rank(V, 0);    // Initialize rank array for union-find

    cout << "Minimum Spanning Tree (Kruskal's Algorithm):" << endl;

    for (const Edge &edge : edges)
    {
        int rootSrc = find(edge.src, parent);
        int rootDest = find(edge.dest, parent);

        // If including this edge doesn't form a cycle, include it in the MST
        if (rootSrc != rootDest)
        {
            cout << "Edge: (" << edge.src << "-" << edge.dest << ") with weight " << edge.weight << endl;
            unionSets(rootSrc, rootDest, parent, rank);
        }
    }
}

int main()
{
    // Example graph represented using edges with weights
    KruskalMST mst(4);

    mst.addEdge(0, 1, 10);
    mst.addEdge(0, 2, 6);
    mst.addEdge(0, 3, 5);
    mst.addEdge(1, 3, 15);
    mst.addEdge(2, 3, 4);

    // Running Kruskal's algorithm
    mst.runKruskal();

    return 0;
}
