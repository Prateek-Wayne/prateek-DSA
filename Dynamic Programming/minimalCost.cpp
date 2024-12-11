#include <bits/stdc++.h>
using namespace std;

int helper(int n,int k,vector<int> &height)
{
    if(n==0)
        return 0;
    int left=helper(n-1,k,height)+abs(height[n]-height[n-1]);
    int right=INT_MAX;
    for(int i=2;i<=k;i++)
    {
        if(n>=i)
        {
            right=helper(n-i,k,height)+abs(height[n]-height[n-i]);

        }
    }
    return min(left,right);

}

int minimizeCost(int k, vector<int> &arr)
{
    return helper(arr.size()-1,k,arr);

}
int main()
{
    //  k = 3, arr[]= [10, 30, 40, 50, 20]
    // vector<int> arr = {10, 30, 40, 50, 20};
    vector<int> arr = {10,20,10};
    int k = 1;
    cout << minimizeCost(k, arr) << endl;
    return 0;
}