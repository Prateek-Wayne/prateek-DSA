#include<bits/stdc++.h>
using namespace std;

long long inversionCount=0;

void mergeIng(long long *arr,int low,int mid,int high)
{
    int left=low;
    int right=mid+1;
    vector<int> temp;
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
            inversionCount+=mid-left+1;
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

void mergeSort(long long *arr,int low,int high)
{   
    if(low==high)
        return ;
    int mid=low+(high-low)/2;
    mergeSort(arr,low,mid);
    mergeSort(arr,mid+1,high);
    mergeIng(arr,low,mid,high);
    


}

long long getInversions(long long *arr, int n){
    mergeSort(arr,0,n-1);
    return inversionCount;
    
}

int main()
{   
     int n = 5;
    // long long arr[] = {10, 9, 8, -4, -1, 5, 4, 3, 2, 1};
    long long arr[] = {2,5,1,3,4};
    mergeSort(arr, 0, n-1);

    // Print sorted array to verify
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout<<"InversionCount"<<inversionCount;

    return 0;




}