//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    long maximumSumSubarray(int k, vector<int> &arr , int N){
        // code here 
        int i=0,j=0;
        long long sum=0,maxy=-99999;
        while(j<N)
        {
            if(j-i+1<k)
            {
                sum+=arr[j];
                  maxy=max(maxy,sum);
                  j++;
            }
            else if(j-i+1==k)
            {
                sum+=arr[j];
                maxy=max(maxy,sum);
                sum-=arr[i];
                j++;
                i++;
                
            }
        }
        return maxy;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N,K;
        cin >> N >> K;;
        vector<int>Arr;
        for(int i=0;i<N;++i){
            int x;
            cin>>x;
            Arr.push_back(x);
        }
        Solution ob;
        cout << ob.maximumSumSubarray(K,Arr,N) << endl;
    }
    return 0; 
} 
// } Driver Code Ends