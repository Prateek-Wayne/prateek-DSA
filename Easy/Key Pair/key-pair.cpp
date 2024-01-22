//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// Function to check if array has 2 elements
	// whose sum is equal to the given value
	bool hasArrayTwoCandidates(int arr[], int n, int X) {
	    // code here
	    sort(arr,arr+n);
	    int low=0;
	    int high=n-1;
	    while(low<high)
	    {
	        if(arr[low]+arr[high]>X)
	            high--;
	        else if(arr[low]+arr[high]<X)
	            low++;
	        else if(arr[low]+arr[high]==X)
                return true;
	        
	    }
	    return false;
	    
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.hasArrayTwoCandidates(arr, n, x);
        cout << (ans ? "Yes\n" : "No\n");
    }
    return 0;
}

// } Driver Code Ends