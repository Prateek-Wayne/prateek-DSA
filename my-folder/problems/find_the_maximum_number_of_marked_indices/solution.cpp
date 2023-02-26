class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& tp) {
           sort(tp.begin(),tp.end());
        int n = tp.size();
        int y = 0, z = (tp.size()+1)/2;
        while(z < n){
            if(tp[y] * 2 <= tp[z])y++;
            z++;
        }
        return y*2;
    }
};