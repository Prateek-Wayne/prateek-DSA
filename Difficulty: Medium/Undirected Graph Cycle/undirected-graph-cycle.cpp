//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
  
bool BFS(vector<int> adj[],vector<int> &Visited,int Node)
{
    Visited[Node]=1;
    queue<pair<int,int>> q;
    q.push({Node,-1});
    while(!q.empty())
    {
        auto it=q.front();
        q.pop();
        for(auto i:adj[it.first])
        {
            if(!Visited[i])
            {
                Visited[i]=1;
                q.push({i,it.first});
            }
            else if(i!=it.second && Visited[i]==1)
                return true;
        }
    }
    return false;

}

bool isCycle(int V, vector<int> adj[])
{
    vector<int> Visited(V,0);
    for(int i=0;i<V;i++)
    {
        if(!Visited[i])
        {
            if(BFS(adj,Visited,i))
            return true;
        }
    }
    return false;
}
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends