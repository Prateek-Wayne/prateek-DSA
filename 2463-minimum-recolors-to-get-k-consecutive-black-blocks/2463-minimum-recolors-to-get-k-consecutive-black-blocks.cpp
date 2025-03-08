class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size();
        int l = 0, r = 0;
        int ans = INT_MAX;
        int white = 0, black = 0;
        while (r < n) {
            blocks[r] == 'W' ? white++ : black++;
            if (r - l + 1 < k)
                r++;
            else if (r - l + 1 == k) {
                ans = min(ans, white);
                blocks[l] == 'W' ? white-- : black--;
                l++;
                r++;
            }
        }
        return ans;
    }
};