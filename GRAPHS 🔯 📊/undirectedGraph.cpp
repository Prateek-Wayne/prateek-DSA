#include <bits/stdc++.h>
using namespace std;

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

int main()
{
}