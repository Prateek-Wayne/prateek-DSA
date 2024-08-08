#include <bits/stdc++.h>
using namespace std;

void setZeroes(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    vector<int> row( n,1);
    vector<int> cols( m,1);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 0)
            {
                row[i] = 0;
                cols[j] = 0;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (row[i] == 0 || cols[j] == 0)
            {
                matrix[i][j]=0;
            }
        }
    }
    for(auto i:matrix)
    {
        for(auto j:i)
        {
            cout<<j<<"|";
        }
        cout<<endl;
    }
}
int main()
{
    vector<vector<int>> matrix = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    // setZeroes(matrix);
    vector<int> m(5,1);
    m[0]=0;
   for(int i=0;i<m.size();i++)
   {
    if(m[i])
        cout<<"true"<<"|";
    else
        cout<<"false"<<"|";
   }
    return 0;
}