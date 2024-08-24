#include<bits/stdc++.h>
using namespace std;

int reversePairCount=0;

void mergeIng(vector<int>& arr,int low,int mid,int high)
{
    int left=low;
    int right=mid+1;
    vector<int> temp;
    int left2=low;
    int right2=mid+1;
    for(int i=left2;i<=mid;i++)
    {
        while(right2<=high && arr[i]>2*arr[right2])
        {
            right2++;
        }
        reversePairCount+=right2-(mid+1);
    }
     while (left<=mid && right<=high)
     {
        if(arr[left]<=arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            right++;
        }
     }
     while(left<=mid)
        temp.push_back(arr[left++]);
    while(right<=high)
        temp.push_back(arr[right++]);

    for(int i=low;i<=high;i++)
    {
        arr[i]=temp[i-low];
    }

}

// void countPairs(vector<int> &arr,int low,int mid,int high)
// {
//     int left=low;
//     int right=mid+1;
//     for(int i=low;i<=mid;i++)
//     {
//         while(right<=high && arr[i]> 2*arr[right])
//             right++;
//         reversePairCount+=(right-(mid+1));
//     }

// }

void mergeSort(vector<int>& arr,int low,int high)
{   
    if(low==high)
        return ;
    int mid=low+(high-low)/2;
    mergeSort(arr,low,mid);
    mergeSort(arr,mid+1,high);
    // countPairs(arr,low,mid,high);
    mergeIng(arr,low,mid,high);
}

//  int reversePairs(vector<int>& arr) {

        
// }

int main()
{   
    // long long arr[] = {10, 9, 8, -4, -1, 5, 4, 3, 2, 1};
    // vector<int> arr={1,3,2,3,1};
    // vector<int> arr={2,4,3,5,1};
    vector<int> arr={2147483647,2147483647,2147483647,2147483647,2147483647,2147483647};
    
    mergeSort(arr, 0, arr.size()-1);

    // Print sorted array to verify
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout<<"ReversePair"<<reversePairCount;

    return 0;




}