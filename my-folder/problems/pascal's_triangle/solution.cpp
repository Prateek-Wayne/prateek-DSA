class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle;
        for(int i=0;i<numRows;i++)
        {
            vector<int> v;
            for(int j=0;j<i+1;j++)
            {
                v.push_back(0);
            }
            triangle.push_back(v);
        }
         for(int i=0;i<numRows;i++)
        {
            for(int j=0;j<i+1;j++)
            {
                if(j==0||j==i)
                    triangle[i][j]=1;
                else
                {
                triangle[i][j]=triangle[i-1][j-1]+triangle[i-1][j];
                }
            }
        }
        return triangle;
    }
};