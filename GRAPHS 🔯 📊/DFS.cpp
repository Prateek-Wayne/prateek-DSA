#include <bits/stdc++.h>
using namespace std;

void DFS(vector<int> adj[], vector<int> &Visited, int Node,vector<int> &ans)
{
    ans.push_back(Node);
    // Visited[Node] = 1;
    for (auto i : adj[Node])
    {
        if (Visited[i] == 0)
        {
            Visited[i] = 1;
            DFS(adj, Visited, i,ans);
        }
    }
    return;
}
 vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> ans;
        vector<int> Visited(V,0);
        Visited[0]=1;
        DFS(adj,Visited,0,ans);
        return ans;

    }

int main()
{
    int V = 5;
    vector<int> adj[] = {
        {2, 3, 1},
        {0},
        {0, 4},
        {0},
        {2}};
    vector<int> Visited(V,0);
    Visited[0]=1;
    DFS(adj,Visited,0);
   
}