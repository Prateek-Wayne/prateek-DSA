//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
  
 vector<long long> nextLargerElement(vector<long long> arr, int n) {
    stack<long long> st;
    vector<long long> ans;

    for (long long i = n - 1; i >= 0; i--) {
        // While stack is not empty and top element is smaller or equal to current element
        while (!st.empty() && st.top() <= arr[i]) {
            st.pop();  // Remove all elements smaller than or equal to current element
        }

        // If stack is empty, no greater element exists, push -1
        if (st.empty()) {
            ans.push_back(-1);
        } else {
            // Top of the stack is the next greater element
            ans.push_back(st.top());
        }

        // Push the current element to stack for future comparison
        st.push(arr[i]);
    }

    // Since we're iterating from the end, we reverse the result
    reverse(ans.begin(), ans.end());
    return ans;
}
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        
        int n;
        cin>>n;
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        Solution obj;
        vector <long long> res = obj.nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
}
// } Driver Code Ends