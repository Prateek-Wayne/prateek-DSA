class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        vector<int> x,y;
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]==0)
                    {
                        x.push_back(i);
                        y.push_back(j);
                    }
                
            }
        }  
        for(auto r:x)
        {
            for(int i=0;i<m;i++)
                matrix[r][i]=0;
        }
        for(auto c:y)
        {
            for(int i=0;i<n;i++)
                matrix[i][c]=0;
        }
    }
};