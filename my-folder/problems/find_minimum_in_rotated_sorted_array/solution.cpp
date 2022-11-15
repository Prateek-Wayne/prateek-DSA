class Solution {
public:
    int findMin(vector<int>& arr) {
        
        
        int low=0;
        int N=arr.size();
        int high=N-1;
        // int mid=0;
        if(arr[low]<=arr[high])
            return arr[low];
        while(low<=high)
        {
             int mid=low+(high-low)/2;
            int next=(mid+1)%N;
            int prev=(mid+N-1)%N;
            
            if(arr[mid]<=arr[prev] && arr[mid]<=arr[next])
                return arr[mid];
            else if(arr[low]<=arr[high])
                return arr[low];
            else if(arr[low]<=arr[mid])
                low=mid+1;
            // else if(arr[mid]<=arr[high])
            //     high=mid-1;
            else 
                high=mid-1;
           
        }
        return arr[0];
        
    }
};