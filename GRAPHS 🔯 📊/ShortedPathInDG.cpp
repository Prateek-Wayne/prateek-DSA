#include <bits/stdc++.h>
using namespace std;

void DFS(vector<int> adj[], vector<int> &Visited, vector<int> &ans, int Node)
{
    queue<pair<int, int>> q;
    Visited[Node]=1;
    q.push({Node, 0});
    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        ans[it.first]=it.second;
        for (auto i : adj[it.first])
        {
            if (!Visited[i])
            {
                q.push({i, it.second + 1});
                Visited[i]=1;
            }
        }
    }
}

// vector<int> shortestPath(vector<vector<int>> &edges, int N, int M, int src)
void shortestPath(vector<vector<int>> &edges, int N, int M, int src)
{
    vector<int> adj[N];
    vector<int> ans(N,0);
    for (auto i : edges)
    {
        adj[i[0]].push_back(i[1]);
        adj[i[1]].push_back(i[0]);
    }
    vector<int> Visited(N, 0);
    for (int i = 0; i < N; i++)
    {
        if (!Visited[i])
            DFS(adj, Visited, ans, i);
    }
    for (auto i : ans)
        cout << i << " ";
    // return ans;
}

int main()
{
    int n = 9, m = 10;
    vector<vector<int>> edges = {{0, 1}, {0, 3}, {3, 4}, {4, 5}, {5, 6}, {1, 2}, {2, 6}, {6, 7}, {7, 8}, {6, 8}};
    int src = 0;

    shortestPath(edges, n, m, src);

    return 0;
}