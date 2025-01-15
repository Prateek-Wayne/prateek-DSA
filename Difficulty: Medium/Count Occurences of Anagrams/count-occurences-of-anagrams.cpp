//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    int search(string &pat, string &txt) {
        // code here
         map<char, int> mp;
    for (int i = 0; i < pat.size(); i++)
        mp[pat[i]]++;
    int count = mp.size();
    int i = 0, j = 0;
    int N = txt.size();
    int ans = 0;
    while (j < N)
    {
        if (mp.find(txt[j]) != mp.end())
        {
            mp[txt[j]]--;
            if (mp[txt[j]] == 0)
                count--;
        }
        if (j - i + 1 < pat.size())
            j++;
        else
        {
            if (count == 0)
                ans++;
            if (mp.find(txt[i]) != mp.end())
            {
                mp[txt[i]]++;
                if (mp[txt[i]] == 1)
                    count++;
            }
            i++;
            j++;
        }
    }
    return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends