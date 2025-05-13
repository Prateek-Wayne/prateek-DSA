const int mod = 1e9 + 7;
int mod_add(int a, int b) {a = a % mod; b = b % mod; return (((a + b) % mod) + mod) % mod;}

class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        int nums[26] = {0};
        for (char ch : s) nums[ch - 'a']++;
        while (t--) {
            int cur[26] = {0};
            for (int j = 0; j < 26; j++) {
                if (j == 25 && nums[j] > 0) {
                    cur[0] = mod_add(cur[0], nums[j]);
                    cur[1] = mod_add(cur[1], nums[j]);
                } else {
                    if (j < 25) cur[j + 1] = mod_add(cur[j + 1], nums[j]);
                }
            }
            for (int j = 0; j < 26; j++) nums[j] = cur[j];
        }
        int ans = 0;
        for (int i : nums) ans = mod_add(ans, i);
        return (int)ans;
    }
};