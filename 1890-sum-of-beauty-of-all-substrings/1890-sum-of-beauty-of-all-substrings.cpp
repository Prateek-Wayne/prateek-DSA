class Solution {
public:
int beauty(map<char, int> &mp) {
    int minFreq = INT_MAX, maxFreq = 0;
    for (auto &entry : mp) {
        if (entry.second > 0) { // Only consider characters with non-zero frequencies
            minFreq = min(minFreq, entry.second);
            maxFreq = max(maxFreq, entry.second);
        }
    }
    return maxFreq - minFreq;
}

int beautySum(string s) {
    int sum = 0;
    for (int i = 0; i < s.length(); i++) {
        map<char, int> mp;
        for (int j = i; j < s.length(); j++) {
            mp[s[j]]++; // Count the frequency of the current character
            sum += beauty(mp);
        }
    }
    return sum;
}

};