#include <bits/stdc++.h>

using namespace std;


void searchMatrix(vector<vector<int>>& matrix, int target) {
        
    int top=0;
    int down=matrix.size()-1;
    int left=0;
    int right=matrix[top].size();
    while(top <= down)
    {
        int mid=(matrix[top][left]+matrix[down][right-1])/2;
        cout<<"Value of mid : "<<mid<<"and value of top "<<top<<" down"<<down<<endl;
        if(mid>target)
        {
            down--;
        }
        else{
            top++;
        }
    }
    while(left<=right)
    {
       int mid=(matrix[top][left]+matrix[down][right-1])/2;
       if (mid== target)
        {cout<<"mid "<<mid <<endl;
        return;}
        if(mid>target)
            right=mid-1;
        else
            left=mid+1;
    }
    return ;
}

int main()
{
    // Your code
    vector<vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };
    \
    searchMatrix(matrix,11);
    

    return 0;
}