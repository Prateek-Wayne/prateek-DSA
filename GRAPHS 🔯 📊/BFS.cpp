#include <bits/stdc++.h>
using namespace std;

vector<int> bfsOfGraph(int V, vector<int> adj[])
{
    vector<int> ans;
    queue<int> q;
    vector<int> Vis(V, 0);
    q.push(0);
    while(!q.empty())
    {
        auto it=q.front();
        q.pop();
        ans.push_back(it);
        for(auto i:adj[it])
        {
            if(Vis[i]==0)
            {
                Vis[i]=1;
                q.push(i);
            } 
        }
    }
    return ans;
}

int main()
{
}