class Solution {
public:
    void setZeroes(vector<vector<int>>& arr) {
        int n=arr.size();
        int m=arr[0].size();
        set<int> row;
        set<int> column;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(arr[i][j]==0)
                    {
                        row.insert(i);
                        column.insert(j);
                    }
            }
        }
       for(auto x:row)
       {
            for(int i=0;i<m;i++)
                arr[x][i]=0;
       }
       for(auto x:column)
       {
            for(int i=0;i<n;i++)
                arr[i][x]=0;
       }
    }
};