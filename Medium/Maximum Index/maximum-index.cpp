//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
        
    // A[]: input array
    // N: size of array
    // Function to find the maximum index difference.
 int maxIndexDiff(int A[], int N) 
{ 
    // Your code here
    int i=0,j=0;
    vector<int> arrLeft(N,0);
    vector<int> arrRight(N,0);
    arrLeft[0] = A[0];
    for(int x=1;x<N;x++)
    {
        arrLeft[x]=min(arrLeft[x-1],A[x]);
    }
    arrRight[N-1] = A[N-1];
    for(int x=N-2;x>=0;x--)
    {
        arrRight[x]=max(arrRight[x+1],A[x]);
    }
    int maxy=0;
    while(j<N)
    {
        if(arrLeft[i]<=arrRight[j])
        {
            maxy=max(maxy,j-i);
            j++;
        }
        else{
            i++;
        }
    }
    return maxy;
}

};

//{ Driver Code Starts.
  
/* Driver program to test above functions */
int main() 
{
    int T;
    //testcases
    cin>>T;
    while(T--){
        int num;
        //size of array
        cin>>num;
        int arr[num];
        
        //inserting elements
        for (int i = 0; i<num; i++)
            cin>>arr[i];
        Solution ob;
        
        //calling maxIndexDiff() function
        cout<<ob.maxIndexDiff(arr, num)<<endl;    
        
    }
    return 0;
} 
// } Driver Code Ends