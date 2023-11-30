//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
     // Function to find majority element in the array
    // a: input array
    // size: size of input array
    int majorityElement(int arr[], int n)
    {
        
        // your code here
        
        int count=1;
        int res=0;
        for(int i=1;i<n;i++)
        {
            if(arr[res]==arr[i])
            {
                count++;
            }
            else 
            count--;
            if(count==0)
            {
                res=i;
                count=1;
            }
        }
         count=0;
        for(int i=0;i<n;i++)
        {
            if(arr[res]==arr[i])
                count++;
        }
        if(count>n/2)
            return arr[res];
        return -1;
    }
};

//{ Driver Code Starts.

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int arr[n];
        
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.majorityElement(arr, n) << endl;
    }

    return 0;
}

// } Driver Code Ends