//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// function to find longest common subsequence

class Solution {
  public:
    // Function to find the length of the longest common subsequence in two strings.
   int getLCSLength(string &s1, string &s2)
{
    // your code here
    int ind1 = s1.size();
    int ind2 = s2.size();
    vector<vector<int>> dp(ind1 + 1, vector<int>(ind2 + 1, -1));
    // bases
    for (int i = 0; i <= ind1; i++)
    {
        dp[i][0] = 0;
    }
    for (int j = 0; j <= ind2; j++)
    {
        dp[0][j] = 0;
    }
    for (int i = 1; i <= ind1; i++)
    {
        for (int j = 1; j <= ind2; j++)
        {

            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[ind1][ind2];
}
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2; // Take both the strings as input
        Solution ob;
        cout << ob.getLCSLength(s1, s2) << endl; // Call the getLCSLength function
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends