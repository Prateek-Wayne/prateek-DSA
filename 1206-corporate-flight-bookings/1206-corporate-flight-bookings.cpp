class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
            vector<int> ans(n,0);
    for(auto b:bookings){
        for(int  i=b[0]-1;i<=b[1]-1;i++){
            ans[i]+=b[2];
        }
    }
    return ans;
    }
};