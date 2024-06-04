class Solution {
public:
void setZeroes(std::vector<std::vector<int>>& matrix) {
    std::vector<std::vector<int>> store;

    // Collect positions of zeroes
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            if (matrix[i][j] == 0) {
                store.push_back({i, j});
            }
        }
    }
    for(auto i:store)
    {   // row 
        int row=i[0];
        for(int j=0;j<matrix[row].size();j++)
        {
            matrix[row][j]=0;
        }
        //columns 
        int col=i[1];
for(int j=0;j<matrix.size();j++)
{
    matrix[j][col]=0;
}
    }

    // for(auto i:matrix)
    // {
    //     for(auto j:i)
    //     {
    //         cout<<j<<"|";
    //     }
    //     cout<<endl;
    // }
}
};