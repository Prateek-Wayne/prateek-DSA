class Solution {
public:
    int find(vector<int>& tops, vector<int>& bottoms, int val) {
        int n = tops.size();
        int topSwap = 0, bottomSwap = 0;
        for (int i = 0; i < n; i++) {
            if (tops[i] != val && bottoms[i] != val)
                return -1;
            else if (tops[i] != val) {
                topSwap++;
            } else if (bottoms[i] != val)
                bottomSwap++;
        }
        return min(topSwap, bottomSwap);
    }

    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size();
        int ans = INT_MAX;
        for (int i = 1; i <= 6; i++) {
            int swaps = find(tops, bottoms, i);
            if (swaps != -1)
                ans = min(swaps, ans);
        }
        return ans == INT_MAX ? -1 : ans;
    }
};