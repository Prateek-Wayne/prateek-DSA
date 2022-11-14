class Solution {
public:
    vector<int> searchRange(vector<int>& arr, int target) {
        vector<int> v={-1,-1};
        int low=0;
        int high=arr.size()-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(arr[mid]==target)
            {
                v[0]=mid;
                high=mid-1;
            }
            else if(arr[mid]>target)
                high=mid-1;
            else
                low=mid+1;
            
        }
          low=0;
         high=arr.size()-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(arr[mid]==target)
            {
                v[1]=mid;
                low=mid+1;
            }
            else if(arr[mid]>target)
                high=mid-1;
            else
                low=mid+1;
            
        }
        return v;
    }
};