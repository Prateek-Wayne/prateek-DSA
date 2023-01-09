class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        map<int,vector<int> > m;
        for(auto i:edges)
        {
            m[i[0]].push_back(i[1]);
            m[i[1]].push_back(i[0]);
        }
        //creating bfs traversal;
        vector<bool> visited(n+1,false);
        visited[source]=true;
        queue<int> q;
        q.push(source);
        while(!q.empty())
        {
            int u=q.front();
            q.pop();
            visited[u]=true;
            for(auto i:m[u])
            {
                if(visited[i]==false)
                {
                    visited[i]=true;
                    q.push(i);
                }
            }
        if(visited[destination]==true)
            return true;
        }
        return visited[destination];
    }
};