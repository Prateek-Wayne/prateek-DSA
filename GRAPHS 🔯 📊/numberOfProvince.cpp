#include<bits/stdc++.h>
using namespace std;

void createAdjList(vector<vector<int>>& isConnected)
{   
    int V=isConnected.size();
    vector<int> adj[V];
    for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
        {
            if(i!=j && isConnected[i][j]==1)
            {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    return adj;
}

void DFS(vector<int> adj[],vector<int> Visited,int Node)
{
    Visited[Node]=1;
    for(auto i:adj[Node])
    {
        if(Visited[i]==0)
        {   
            Visited[i]=1;
            DFS(adj,Visited,i);
        }
    }

}

int findCircleNum(vector<vector<int>>& isConnected) {
    // creating adj list...
    int V=isConnected.size();
    vector<int> adj[V];
    for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
        {
            if(i!=j && isConnected[i][j]==1)
            {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    int n=isConnected.size();

    int count=0;
    vector<int> Visited(n,0);
    for(int i=0;i<n;i++)
    {
        if(Visited[i]==0)
        {
            count++;
            DFS(adj,Visited,i);
        }
    }
    return count;

}

int main()
{
    vector<vector<int>> isConnected = {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};
    createAdjList(isConnected);

}