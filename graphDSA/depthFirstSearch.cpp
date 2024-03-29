#include <iostream>
#include <vector>
#include <forward_list>
#include <stack>
using namespace std;
void addEdge(vector<forward_list<int>> &adjlist, int u, int v)
{
    adjlist[u].push_front(v);
    adjlist[v].push_front(u);
}
void dfs(vector<forward_list<int>> adjlist, int start)
{
    int n = adjlist.size();
    vector<bool> visited(n, false);
    stack<int> dfstack;

    dfstack.push(start);
    visited[start] = true;

    cout << "BFS start from " << start << " is : ";
    while (!dfstack.empty())
    {
        int current = dfstack.top();
        dfstack.pop();
        cout << current << "  ";
        for (int neighbour : adjlist[current])
        {
            if (!visited[neighbour])
            {
                dfstack.push(neighbour);
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
    dfs(adjlist, 1);
    return 0;
}