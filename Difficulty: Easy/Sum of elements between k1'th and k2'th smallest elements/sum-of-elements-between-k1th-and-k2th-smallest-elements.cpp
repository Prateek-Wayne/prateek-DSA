//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
  long long sumBetweenTwoKth(long long A[], long long N, long long K1, long long K2)
{
    // Your code goes here
    priority_queue<long long> maxHeap1;
    priority_queue<long long> maxHeap2;
    for (long long i = 0; i < N; i++)
    {
        maxHeap1.push(A[i]);
        if (maxHeap1.size() > K1)
            maxHeap1.pop();
        maxHeap2.push(A[i]);
        if (maxHeap2.size() > K2)
            maxHeap2.pop();
    }
     long long sum = -maxHeap2.top();
    while (!maxHeap2.empty())
    {
        sum += maxHeap2.top();
        maxHeap2.pop();
    }
    while (!maxHeap1.empty())
    {
        sum -= maxHeap1.top();
        maxHeap1.pop();
    }
    return sum;
}
};

//{ Driver Code Starts.
int main()
 {
    long long t;
    cin>>t;
    while(t--)
    {
        long long n, k;
        cin>>n;
        long long a[n+5];
        for(int i =0;i<n;i++)
            cin >> a[i];
        
        long long k1, k2;
        cin >> k1 >> k2;
        Solution ob;
        cout << ob.sumBetweenTwoKth(a, n, k1, k2) << endl;
        
    
cout << "~" << "\n";
}
	return 0;
}

// } Driver Code Ends