#include <bits/stdc++.h>
using namespace std;

int helper(vector<int> &height,int n) // n is 0 based n-1...
{
    if(n==0)
        return 0;
    
    int left =helper(height,n-1)+abs( height[n]-height[n-1]);
    int right=INT_MAX;
    if(n>1)
    {
        right=helper(height,n-2)+abs(height[n]-height[n-2]);
    }
    return min(left,right);

}

int minimumEnergy(vector<int> &height, int n)
{
    // Code here
    return helper(height,n);
    
}

int main()
{
    vector<int> height = {10, 30, 40};
    int n = 3;
    cout << minimumEnergy(height, n);
    return 0;
}