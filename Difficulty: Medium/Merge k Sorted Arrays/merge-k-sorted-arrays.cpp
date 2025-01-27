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
vector<int> mergeKArrays(vector<vector<int>> arr, int K)
{
    // code here//{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}
    struct customDataType
    {
        int data;
        int rPos;
        int cPos;
        customDataType(int value, int row, int col)
        {
            this->data = value;
            this->rPos = row;
            this->cPos = col;
        }
    };

    struct compare
    {
        bool operator()(customDataType const &a, customDataType const &b)
        {
            return a.data > b.data; //
        }
    };

    priority_queue<customDataType, vector<customDataType>, compare> minHeap;

    vector<int> ans;
    for (int i = 0; i < K; i++)
    {
        customDataType value(arr[i][0], i, 0);
        minHeap.push(value);
    }
    while (!minHeap.empty())
    {
        customDataType top = minHeap.top();
        minHeap.pop();
        ans.push_back(top.data);
        if (top.cPos + 1 < arr[top.rPos].size())
        {
            customDataType value(arr[top.rPos][top.cPos + 1], top.rPos, top.cPos + 1);
            minHeap.push(value);
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
    
cout << "~" << "\n";
}
	return 0;
}






// } Driver Code Ends