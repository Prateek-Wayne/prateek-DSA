#include <bits/stdc++.h>
using namespace std;

bool isCycle(int V, vector<int> adj[])
{
    queue<pair<int,int>> q;
    q.push({0,-1});
    vector<int> Visited(V,0);
    Visited[0]=1;
    while(!q.empty())
    {
        auto it=q.front();
        q.pop();
        for(auto i: adj[it.first])
        {
            if(i==it.second) continue;
            else if(Visited[i]==1)
                return true;
            else{
                Visited[i]=1;
                q.push({i,it.first});
            }
        }
    }
    return false;
}

int main()
{
}