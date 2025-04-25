class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n=gain.size();
        vector<int> ans(n+1,0);
        for(int i=1;i<=n;i++){
            ans[i]=gain[i-1]+ans[i-1];
        }
        int maxy=INT_MIN;
        for(auto i:ans){
            maxy=max(maxy,i);
        }
        return maxy;
    }
};