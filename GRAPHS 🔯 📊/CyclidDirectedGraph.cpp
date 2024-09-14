#include <bits/stdc++.h>
using namespace std;
bool isCyclic2(int V, vector<int> adj[])
{
    // code here
    queue<pair<int,int>> q;
    vector<int> Visited(V,0);
    for(int i=0;i<V;i++)
    {
        if(!Visited[i])
        {
            q.push({i,-1});
            Visited[i]=1;

            while(!q.empty())
            {
                auto it=q.front();
                q.pop();
                for(auto x:adj[it.first])
                {
                    if(x==it.second)
                        return true;
                    Visited[x]=1;
                    q.push({x,it.first});
                }
            }
        }
    }
    return false;
}

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
int main()
{
    int V = 6;
    vector<int> adj[] = {
        {},     // Node 0
        {},     // Node 1
        {3},    // Node 2
        {1},    // Node 3
        {0, 1}, // Node 4
        {2, 0}  // Node 5
    };

    cout << "Topological Sort of the given graph: ";


    return 0;
}