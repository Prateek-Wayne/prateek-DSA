class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        long long modd=1e9+7;
        long long odd=0 ,even=1 ,ans=0 ,sum=0;
        for(int i=0;i<arr.size();i++)
        {
            sum+=arr[i];
            if(sum &1)
            {
                ans+=even;
                odd++;
            }
            else
            {
                ans+=odd;
                even++;
            }
        }
        return ans%modd;
    }
};