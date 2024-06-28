class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
          int n = matrix[0].size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
        
         for(int i=0;i<n;i++)
    {
        reverse(matrix[i].begin(),matrix[i].end());
    }
        
    // for (int i = 0; i < n; i++)
    // {
    //     int last = n - 1;
    //     while (last >= 0)
    //     {
    //         swap(matrix[i][last], matrix[last][i]);
    //         last--;
    //     }
    // }
    }
};