//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // You need to complete this function


int towerOfHanoi(int n, int source, int aux, int dest)
{
    
    int count = 0;
    helper(n, source, aux, dest, count);
    return count;
}

void helper(int n, int source, int aux, int dest, int &count)
{
    if(n==0)
        return ;
    if (n == 1)
    {
        count++;
        return;
    }
    helper(n - 1, source, dest, aux, count);
    count++;
    helper(n - 1, aux, source, dest, count);
}
};


//{ Driver Code Starts.

int main() {

    int T;
    cin >> T; // testcases
    while (T--) {

        int N;
        cin >> N; // taking input N

        // calling toh() function
        Solution ob;

        cout << ob.towerOfHanoi(N, 1, 3, 2) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends