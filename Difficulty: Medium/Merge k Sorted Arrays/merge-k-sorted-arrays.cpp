//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}


// } Driver Code Ends
//User function Template for C++


class Solution
{
    public:
    //Function to merge k sorted arrays.

class Data {
public:
    int value;
    int row;
    int col;
    Data(int v, int r, int c) {
        value = v;
        row = r;
        col = c;
    }
};

// Custom comparator for min-heap
struct CompareData {
    bool operator()(Data const& d1, Data const& d2) {
        return d1.value > d2.value; // Min-heap: smallest element at the top
    }
};

vector<int> mergeKArrays(vector<vector<int>> arr, int K) {
    priority_queue<Data, vector<Data>, CompareData> q;
    vector<int> ans;

    for (int i = 0; i < K; i++) {
        Data data(arr[i][0], i, 0);
        q.push(data);
    }
    while (!q.empty()) {
        auto it = q.top();
        q.pop();
        ans.push_back(it.value);
        int r = it.row;
        int c = it.col + 1;
        if (c < arr[r].size()) {
            Data data(arr[r][c], r, c);
            q.push(data);
        }
    }
    return ans;
}
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int>> arr(k, vector<int> (k, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
    }
	return 0;
}






// } Driver Code Ends