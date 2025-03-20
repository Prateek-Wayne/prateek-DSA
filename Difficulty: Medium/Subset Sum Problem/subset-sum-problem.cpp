//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:

bool helper(vector<int> &arr, int index, int sum, vector<vector<int>> &dp)
{
    if (sum < 0)
        return false;
    if (sum == 0)
        return true;
    if (index == 0)
    {
        if (sum == arr[0])
            return true;
        return false;
    }
    // if(dp[])
    if (dp[index][sum] != -1)
        return dp[index][sum];
    // pick
    sum -= arr[index];
    int left = helper(arr, index - 1, sum, dp);
    sum += arr[index];
    int right = helper(arr, index - 1, sum, dp);
    return dp[index][sum] = left || right;
}

bool isSubsetSum(vector<int> &arr, int sum)
{
    // int sum = 0;
    int index = arr.size();
    vector<vector<int>> dp(index + 1, vector<int>(sum + 1, -1));
    return helper(arr, index - 1, sum, dp);
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