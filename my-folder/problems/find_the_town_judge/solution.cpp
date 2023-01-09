class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        //very simple ,alculate indegree +Outdegree
        vector<int> v (n+1,0);
        for(auto i: trust)
        {
            v[i[0]]--;
            v[i[1]]++;

        }
        for(int i=1;i<=n;i++)
        {
            if(v[i]==n-1)
                return i;
        }
        return -1;
    }
};