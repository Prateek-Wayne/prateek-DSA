//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
typedef pair<int, int> p;
vector<int> topKFrequent(vector<int> &arr, int k)
{
    // Code here
    priority_queue<p, vector<p>, greater<p>> minHeap;
    unordered_map<int, int> mp;
    for (int i = 0; i < arr.size(); i++)
    {
        mp[arr[i]]++;
    }
    for (auto i : mp)
    {
        p temp = {i.second, i.first};
        minHeap.push(temp);
        if (minHeap.size() > k)
            minHeap.pop();
    }
    vector<int> ans;
    while (!minHeap.empty())
    {
        p temp = minHeap.top();
        ans.push_back(temp.second);
        minHeap.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();

    while (t--) {

        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        vector<int> res = obj.topKFrequent(arr, k);
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends