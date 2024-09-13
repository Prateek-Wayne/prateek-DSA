#include <bits/stdc++.h>
using namespace std;

void DFS(vector<int> adj[], vector<int> &Visited, vector<int> &ans, int Node)
{
    Visited[Node] = 1;
    for (auto i : adj[Node])
    {
        if (!Visited[i])
            DFS(adj, Visited, ans, i);
    }
    ans.push_back(Node);
}

vector<int> topoSort(int V, vector<int> adj[])
{
    vector<int> Visited(V, 0);
    vector<int> ans;
    for (int i = 0; i < V; i++)
    {
        if (!Visited[i])
        {
            DFS(adj, Visited, ans, i);
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    int V = 6;
    vector<int> adj[] = {
        {},     // Node 0
        {},     // Node 1
        {3},    // Node 2
        {1},    // Node 3
        {0, 1}, // Node 4
        {2, 0}  // Node 5
    };

    cout << "Topological Sort of the given graph: ";
    topoSort(V, adj);

    return 0;
}