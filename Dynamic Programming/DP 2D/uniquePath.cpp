#include <bits/stdc++.h>
using namespace std;

int helper(int R,int C,int m,int n,int &count)
{
    // base...
    if(R==m && C==n)
    {
        count++;
        return count;
    }

    if(R+1<=m)
    {
        return helper(R+1,C,m,n,count);
    }
    if(C+1<=n)
    {
        return helper(R,C+1,m,n,count);
    }
    else    
        return 0;
}

int uniquePaths(int m, int n)
{
    int count=0;
    return helper(0,0,m-1,n-1,count);
}
int main()
{   
    return uniquePaths(3,2);
    return 0;
}