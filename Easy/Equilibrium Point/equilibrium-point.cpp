//{ Driver Code Starts
#include <iostream>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    int equilibriumPoint(long long arr[], int n) {
    
        // Your code here
        if(n==1)
            return 1;
        long long total=0,L=0,R=0;
        for(int i=0;i<n;i++)
        {
            total+=arr[i];
        }
        R=total-arr[0];
        for(int i=1;i<n;i++)
        {   
            if(L==R)
                return i;
            L+=arr[i-1];
            R-=arr[i];
        }
        return -1;
    }

};

//{ Driver Code Starts.


int main() {

    long long t;
    
    //taking testcases
    cin >> t;

    while (t--) {
        long long n;
        
        //taking input n
        cin >> n;
        long long a[n];

        //adding elements to the array
        for (long long i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        Solution ob;

        //calling equilibriumPoint() function
        cout << ob.equilibriumPoint(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends