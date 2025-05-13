class Solution {
public:

vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    int m = matrix.size(), n = matrix[0].size();
    int i=0,j=0;
    vector<int> ans;
    while(i<m && j<n){
       for(int y=j;y<n;y++){
            ans.push_back(matrix[i][y]);
       }
       i++;
       for(int x=i;x<m;x++){
        ans.push_back(matrix[x][n-1]);
       }
       n--;
       if(i<m){
           for(int y=n-1;y>=j;y--){
            ans.push_back(matrix[m-1][y]);
           }
           m--;
       }
       if(j<n){
           for(int x=m-1;x>=i;x--){
            ans.push_back(matrix[x][j]);
           }
           j++;
       }
    }
    return ans;
}
};