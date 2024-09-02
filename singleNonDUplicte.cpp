#include <bits/stdc++.h>
using namespace std;
int singleNonDuplicate(vector<int> &arr)
{
    int low=0;
    int high= arr.size()-1;
    while(low<=high)
    {
        int mid=low+(high-low)/2;
        if(mid%2!=0 && arr[mid]==arr[mid-1])
        {
            low=mid+1;
        }
        else if(mid%2==0 && arr[mid]==arr[mid-1] )
        {
            high=mid-1;
        }
        else{
            return arr[mid];
        }

    }
    return -1;
}

int main()
{
    vector<int> arr={1,1,2,3,3,4,4,8,8};
    cout<<singleNonDuplicate(arr);
}