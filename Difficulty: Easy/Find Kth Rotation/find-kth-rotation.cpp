//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
   
int findKRotation(vector<int> &arr)
{
    int low = 0, high = arr.size() - 1;
    pair<int, int> ans = {INT_MAX, -1};
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[low] <= arr[mid])
        {
            if (arr[low] <= ans.first)
            {
                ans.first = arr[low];
                ans.second = low;
            }

            low = mid + 1;
        }
        else
        {
            if (arr[mid] <= ans.first)
            {
                ans.first = arr[mid];
                ans.second = mid;
            }
            high = mid - 1;
        }
    }
    return ans.second;
}
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input1;
        getline(cin, input1);
        stringstream ss1(input1);
        int number1;
        while (ss1 >> number1) {
            arr.push_back(number1);
        }
        Solution ob;
        int res = ob.findKRotation(arr);
        cout << res << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends