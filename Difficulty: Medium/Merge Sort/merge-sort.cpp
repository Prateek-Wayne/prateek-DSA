//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;



/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


// } Driver Code Ends
class Solution
{
    public:
 
void mergeMe(int arr[], int l, int m, int h)
{
    vector<int> temp;
    int left=l;
    int right = m + 1;
    while (l <= m && right <= h)
    {
        if (arr[l] <= arr[right])
        {
            temp.push_back(arr[l]);
            l++;
        }
        else
        {
            temp.push_back(arr[right]);
            right++;
        }
    }
    while (l <= m)
    {
        temp.push_back(arr[l]);
        l++;
    }
    while (right <= h)
    {
        temp.push_back(arr[right]);
        right++;
    }
    for (int i = left; i <= h; i++)
    {
        arr[i] = temp[i-left];
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l >= r)
        return;
     int mid = l + (r - l) / 2;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid + 1, r);
    mergeMe(arr, l, mid, r);
}
};

//{ Driver Code Starts.


int main()
{
    int n,T,i;

    scanf("%d",&T);

    while(T--){
    
    scanf("%d",&n);
    int arr[n+1];
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    Solution ob;
    ob.mergeSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends