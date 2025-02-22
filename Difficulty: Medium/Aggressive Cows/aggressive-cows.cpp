//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:

bool isPossible(vector<int> &stalls, int distance, int cows)
{
    int noOfCows = 1;
    int previouseStall = stalls[0];
    for (int i = 1; i < stalls.size(); i++)
    {
        int currentStall = stalls[i];
        if (currentStall - previouseStall >= distance)
        {
            noOfCows++;
            previouseStall = currentStall;
        }
    }
    if (noOfCows >= cows)
        return true;
    return false;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    sort(stalls.begin(), stalls.end());
    int low = 1, high = INT_MAX;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (isPossible(stalls, mid, k))
            low = mid + 1;
        else
            high = mid - 1;
    }
    return high;
}
};

//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int k;
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string in;
        getline(cin, in);
        stringstream sss(in);
        int num;
        while (sss >> num) {
            k = num;
        }
        Solution ob;
        int ans = ob.aggressiveCows(arr, k);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends