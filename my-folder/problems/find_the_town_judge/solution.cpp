class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
       vector<int> visited(n+1,0);
        for(int i=0;i<trust.size();i++)
        {
            // visited[i[0]]--;
            // visited[i[1]]++;
            visited[trust[i][0]]--;
            visited[trust[i][1]]++;
        }
        for(int i=1;i<=n;i++)
        {
            if(visited[i]==n-1)
                return i;
            
        }
        return -1;
    }
};