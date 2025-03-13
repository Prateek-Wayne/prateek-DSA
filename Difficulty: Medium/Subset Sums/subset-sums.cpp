//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  void helper(vector<int> &arr,vector<int>&ds,int index,int &sum,vector<int> &ans){
      if(index==arr.size())
      {
          ans.push_back(sum);
          return;
      }
      
      ds.push_back(arr[index]);
      sum+=arr[index];
      helper(arr,ds,index+1,sum,ans);
      sum-=arr[index];
      ds.pop_back();
      
      helper(arr,ds,index+1,sum,ans);
      
  }
    vector<int> subsetSums(vector<int>& arr) {
       vector<int> ans ;
       vector<int> ds ={};
       int sum=0;
       helper(arr,ds,0,sum,ans);
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