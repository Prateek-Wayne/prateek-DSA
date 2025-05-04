//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:

    // Function to rotate an array by d elements in counter-clockwise direction.

void rotateArr(vector<int> &nums, int k)
{
   int n = nums.size();
    if (n == 0) return;
    vector<int> temp;
    k = k % n;
    if (k == 0)
        return;
    for (int i = 0; i < k; i++)
    {
        temp.push_back(nums[i]);
    }
    for (int i = k; i < n; i++)
    {
        nums[i - k] = nums[i];
    }
    for (int i = n - k; i < n; i++)
    {
        nums[i] = temp[i - (n - k)];
    }
    return;
}
};


//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        // calling rotateArr() function
        ob.rotateArr(arr, d);

        // printing the elements of the array
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends