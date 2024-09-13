//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    
bool DFS(vector<int> adj[],vector<int> &Visited,vector<int> &Path,int Node)
{
    Visited[Node]=1;
    Path[Node]=1;
    for(auto i:adj[Node])
    {
        if(!Visited[i])
        {
            if(DFS(adj,Visited,Path,i)==true)
                return true;
        }
        else if(Path[i])
            return true;
        // else if(Visited[i] && Path[i])
        //     return true;
        // else if(Visited[i] && !Path[i])
        //     continue;
    }
    Path[Node]=0;
    return false;
}

bool isCyclic(int V, vector<int> adj[])
{
    vector<int> Visited(V,0);
    vector<int> Path(V,0);
    for(int i=0;i<V;i++)
    {
        if(!Visited[i])
        {
            if(DFS(adj,Visited,Path,i)==true)
                return true;
        }
    }
    return false;

}
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends