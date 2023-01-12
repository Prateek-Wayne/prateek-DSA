class Solution {
public:
    int mySqrt(int x) {
        int low=1;
        int high=x;
        int res=0;
        while(low<=high)
        {
            long long int mid=low+(high-low)/2;
            // long long int a=mid*mid;
            if(mid*mid<=x)
            {
                res=mid;
                low=mid+1;
            }
            else if(mid*mid>x)
            {
                high=mid-1;
            }
            else
                low=mid+1;
        }
        return res;
    }
};