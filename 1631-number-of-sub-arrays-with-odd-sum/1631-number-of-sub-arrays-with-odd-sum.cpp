class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int mod=1e9+7;
        int even=1;
        int odd=0;
        int n=arr.size();
        vector<int> prefixSum(n,0);
        prefixSum[0]=arr[0];
        long long ans=0;
        for(int i=1;i<n;i++){
            prefixSum[i]=prefixSum[i-1]+arr[i];
        }
        for(int i=0;i<n;i++){
            if(prefixSum[i]&1){
                ans+=even;
                ans=ans%mod;
                odd++;
            }
            else{
                ans+=odd;
                ans=ans%mod;
                even++;
            }
        }
        return ans;
    }
};