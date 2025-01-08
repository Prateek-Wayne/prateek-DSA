//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    
void dfs(vector<vector<int>> &adj, int node, vector<int> &Vis, vector<int> &ans)
{
    Vis[node] = 1;
    for (auto i : adj[node])
    {
        if (!Vis[i])
        {   
            Vis[i]=1;
            ans.push_back(i);
            dfs(adj, i, Vis, ans);
        }
    }
}

vector<int> dfsOfGraph(vector<vector<int>> &adj)
{
    // Code here
    int n = adj.size();
    vector<int> Vis(n, 0);
    vector<int> ans;
    ans.push_back(0);
    for (int i = 0; i < n; i++)
    {
        if (!Vis[i])
            dfs(adj, i, Vis, ans);
    }
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

        vector<vector<int>> adj(
            V); // Use vector of vectors instead of array of vectors.

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        Solution obj;
        vector<int> ans = obj.dfsOfGraph(adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends