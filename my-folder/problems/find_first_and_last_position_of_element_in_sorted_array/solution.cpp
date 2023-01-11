class Solution {
public:
    int firstOcurence(vector<int>& arr, int target)
    {
        int start=0;
        int end=arr.size()-1;
        int res=-1;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(target==arr[mid])
                {
                    res=mid;
                    end=mid-1;
                }
            else if(target<arr[mid])
                end=mid-1;
            else
                start=mid+1;
        }
        return res;

    }
    int lastOcurence(vector<int>& arr, int target)
    {
        int start=0;
        int end=arr.size()-1;
        int res=-1;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(target==arr[mid])
                {
                    res=mid;
                    start=mid+1;
                }
            else if(target<arr[mid])
                end=mid-1;
            else
                start=mid+1;
        }
        return res;

    }
    vector<int> searchRange(vector<int>& nums, int target) {
         vector<int> v;
         int first=firstOcurence(nums,target);
         int last=lastOcurence(nums,target);
         v.push_back(first);
         v.push_back(last);
         return v;
    }
};