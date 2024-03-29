#include <iostream>
#include <vector>
#include <forward_list>
#include <queue>
using namespace std;
void addEdge(vector<forward_list<int>> &adjlist, int u, int v)
{
    adjlist[u].push_front(v);
    adjlist[v].push_front(u);
}
void bfs(vector<forward_list<int>> adjlist, int start)
{
    int n = adjlist.size();
    vector<bool> visited(n, false);
    queue<int> bfsque;

    bfsque.push(start);
    visited[start] = true;

    cout << "BFS start from " << start << " is : ";
    while (!bfsque.empty())
    {
        int current = bfsque.front();
        bfsque.pop();
        cout << current << "  ";
        for (int neighbour : adjlist[current])
        {
            if (!visited[neighbour])
            {
                bfsque.push(neighbour);
                visited[neighbour] = true;
            }
        }
    }
    cout << endl;
}
int main()
{
    vector<forward_list<int>> adjlist(5);
    addEdge(adjlist, 1, 2);
    addEdge(adjlist, 1, 4);
    addEdge(adjlist, 1, 3);
    addEdge(adjlist, 2, 3);
    bfs(adjlist, 1);
    return 0;
}