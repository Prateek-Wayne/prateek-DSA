//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++
class Solution
{
public:

    void utill(int i,int N){
        if(i==N)
        {   cout<<i<<" ";
            return;
        }
        cout<<i<<" ";
        i+=1;
        utill(i,N);
    }
    void printTillN(int N)
    {
        // Write Your Code here
        utill(1,N);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        Solution ob;
        ob.printTillN(N);
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends