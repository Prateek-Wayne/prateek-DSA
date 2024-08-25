#include <bits/stdc++.h>
using namespace std;

// void rearrangeArray(vector<int> &arr)
vector<int> rearrangeArray(vector<int> &arr)
{
    vector<int> ansP;
    vector<int> ansN;
    int n=arr.size();
    for(int i=0;i<n;i++)
    {
        if(arr[i]>=0)
        {
            ansP.push_back(arr[i]);
        }
        else{
            ansN.push_back(arr[i]);
        }
    }
    
    vector<int> ans(n, 0);
    
    int index=0;
    for(auto i:ansP)
    {  
        ans[index]=i;
        index+=2;
    }
    index=1;
    for(auto i:ansN)
    {
        ans[index]=i;
        index+=2;
    }
    return ans;
}

int main()
{
    vector<int> arr={3,1,-2,-5,2,-4};
    rearrangeArray(arr);
}