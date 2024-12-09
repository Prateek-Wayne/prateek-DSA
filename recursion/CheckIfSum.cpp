#include<bits/stdc++.h>
using namespace std;

bool helper(vector<int> ds,vector<int> &arr,int Sum,int k ,int ind)
{
    //
    if(ind==arr.size())
        {
            if(Sum==k)
                return true;
            return false;
        }

        // push...
        Sum+=arr[ind];
        ds.push_back(arr[ind]);
        if(helper(ds,arr,Sum,k,ind+1))
            return true;
        //pop...
        Sum-=arr[ind];
        ds.pop_back();
        if(helper(ds,arr,Sum,k,ind+1))
            return true;
        return false;


}

bool isSubsetPresent(int n, int k, vector<int> &a)
{
    // Write your code here
    vector<int> ds={};
    return helper(ds,a,0,k,0);
}
int main()
{

int n = 5;
int k = 14;
vector<int> a = {4, 2, 5, 6, 7};
if (isSubsetPresent(n, k, a)) {
    cout << "Subset with given sum found" << endl;
} else {
    cout << "Subset with given sum not found" << endl;
}

 return 0;
}