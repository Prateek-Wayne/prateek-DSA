#include <bits/stdc++.h>
using namespace std;

int helper(vector<int> &house,int n,vector<int> & Vis)
{

    if(n==0)
    {   Vis[0]=1;
        return house[0];
    }
    if(n<0)
        return 0;
    Vis[n]=1;
    int pick=INT_MIN;
    if(Vis[(n-1+house.size()) % house.size()] != 1)
         pick=helper(house,n-2,Vis)+house[n];
    int nonPick=helper(house,n-1,Vis)+0;
    return max(pick,nonPick);

}

int rob(vector<int> &nums)
{
    vector<int> Vis(nums.size(),-1);
    return helper(nums,nums.size()-1,Vis);
}
int main()
{   
    vector<int> house={2,3,2};
    return rob(house);
    return 0;
}