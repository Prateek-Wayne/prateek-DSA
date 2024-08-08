class Solution {
public:
    
    int reversePairCount=0;


void mergeIng(vector<int>& arr,int low,int mid,int high)
{
    int left=low;
    int right=mid+1;
    vector<int> temp;
    int left2=low;
    int right2=mid+1;
    for(int i = left2; i <= mid; i++)
{
    while(right2 <= high && arr[i] > 2LL * arr[right2]) // Cast to long long
    {
        right2++;
    }
    reversePairCount += right2 - (mid + 1);
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

    int reversePairs(vector<int>& nums) {
        mergeSort(nums,0,nums.size()-1);
        return reversePairCount;
    }
};