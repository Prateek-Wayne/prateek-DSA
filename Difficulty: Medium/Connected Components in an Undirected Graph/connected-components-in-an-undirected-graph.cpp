//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Matrix {
  public:
    template <class T>
    static void input(vector<vector<T>> &A, int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d ", &A[i][j]);
            }
        }
    }

    template <class T>
    static void print(vector<vector<T>> &A) {
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[i].size(); j++) {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends

class Solution {
  public:

vector<int> dfs(vector<int> adj[], vector<int> &Vis, int start)
{
    queue<int> q;
    vector<int> ans;
    q.push(start);
    vector<int> temp;
    while (!q.empty())
    {
        int top = q.front();
        q.pop();
        temp.push_back(top);
        for (auto j : adj[top])
        {
            if (!Vis[j])
            {
                Vis[j] = 1;
                q.push(j);
            }
        }
    }
    sort(temp.begin(),temp.end());
    return temp;
}

vector<vector<int>> connectedcomponents(int v, vector<vector<int>> &edges)
{
    // code here
    vector<vector<int>> ans;
    vector<int> Vis(v, 0);
    vector<int> adj[v];
    for (auto i : edges)
    {
        adj[i[0]].push_back(i[1]);
        adj[i[1]].push_back(i[0]);
    }
    for (int i = 0; i < v; i++)
    {
        if (!Vis[i])
        {
            Vis[i] = 1;
            vector<int> temp = dfs(adj, Vis, i);
            ans.push_back(temp);
        }
    }
    return ans;
}
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int e;
        scanf("%d", &e);

        int v;
        scanf("%d", &v);

        vector<vector<int>> edges(e, vector<int>(2));
        Matrix::input(edges, e, 2);

        Solution obj;
        vector<vector<int>> res = obj.connectedcomponents(v, edges);
        sort(res.begin(), res.end());
        for (const auto &component : res) {
            for (int node : component) {
                cout << node << " ";
            }
            cout << endl;
        }

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends