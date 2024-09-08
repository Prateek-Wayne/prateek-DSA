//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
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
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends