class Solution {
public:
    int characterReplacement(string s, int k) {
        int i = 0, j = 0, ans = 0;
        map<char, int> mp;
        while (j < s.length()) {
            mp[s[j]]++;
            int maxFreq = 0;
            for (auto i : mp) {
                maxFreq = max(maxFreq, i.second);
            }
            int winLenght = j - i + 1;

            if (winLenght - maxFreq <= k) {
                ans = max(ans, winLenght);
                j++;
            } else {
                while (winLenght - maxFreq > k) {
                    mp[s[i]]--;
                    i++;
                    maxFreq = 0;
                    for (auto x : mp) {
                        maxFreq = max(maxFreq, x.second);
                    }
                    winLenght = j - i + 1;
                }
                if (winLenght - maxFreq == k) {
                    ans = max(ans, winLenght);
                    j++;
                }
            }
        }
        return ans;
    }
};