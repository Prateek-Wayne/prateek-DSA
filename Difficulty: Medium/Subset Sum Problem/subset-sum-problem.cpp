//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
  
    // bool helper(vector<int>& arr,vector<int>& ds, int target,int  i)
    // {
    //     if(i==arr.size())
    //     {   
    //         int sum=0;
    //         for(int i=0;i<ds.size();i++)
    //             sum+=ds[i];
    //         if(sum==target)
    //             return true;
    //         return false;
    //     }

    //     // pick condition...
    //     ds.push_back(arr[i]);
    //     bool left=helper(arr,ds,target,i+1);
    //     ds.pop_back();
    //     bool right=helper(arr,ds,target,i+1);
    //     return left||right;
        
    // }
        bool helper(vector<int>& arr, int target,int  i,int sum, vector<vector<int>> &dp)
    {
        if(sum>target)
            return false;
        if(i==arr.size())
        {   
            if(sum==target)
                return true;
            return false;
        }
        if(dp[i][sum]!=-1)
            return dp[i][sum];

        // pick condition...
        sum+=arr[i];
        bool left=helper(arr,target,i+1,sum,dp);
        sum-=arr[i];
        bool right=helper(arr,target,i+1,sum,dp);
        return dp[i][sum]= left||right;
        
    }
    bool isSubsetSum(vector<int>& arr, int target) {
        vector<int> ds={};
        int n=arr.size();
        vector<vector<int>> dp(n+1,vector<int>(target+1,-1));
        return helper(arr,target,0,0,dp);
        
        
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int sum;
        cin >> sum;
        cin.ignore();

        Solution ob;
        if (ob.isSubsetSum(arr, sum))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends