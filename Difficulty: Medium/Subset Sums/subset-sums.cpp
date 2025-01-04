//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
   void helper(vector<int> arr, int ind, vector<int> ds, vector<int> &ans)
{
    if (ind < 0)
    {
        int sum = 0;
        for (auto i : ds)
            sum += i;
        ans.push_back(sum);
        // cout << sum << endl;
        return;
    }
    ds.push_back(arr[ind]);
    helper(arr, ind - 1, ds, ans);
    ds.pop_back();
    helper(arr, ind - 1, ds, ans);
}
vector<int> subsetSums(vector<int> &arr)
{
    vector<int> ans;
    helper(arr, arr.size() - 1, {}, ans);
    return ans;
}
};

//{ Driver Code Starts.

int main() {
    int t; // Number of test cases
    cin >> t;
    cin.ignore(); // Ignore the newline after the integer input

    while (t--) {
        vector<int> inputArray;
        string inputLine;

        // Input format: first number n followed by the array elements
        getline(cin, inputLine);
        stringstream inputStream(inputLine);
        int num;
        while (inputStream >> num) {
            inputArray.push_back(num); // Read the array elements from input string
        }

        Solution solutionObject;
        vector<int> result = solutionObject.subsetSums(inputArray);
        sort(result.begin(), result.end());

        for (int i = 0; i < result.size(); i++) {
            if (i != 0)
                cout << " ";
            cout << result[i];
        }
        cout
            << endl
            << "~\n"; // Print results in list format with new line after each test case
    }

    return 0;
}

// } Driver Code Ends