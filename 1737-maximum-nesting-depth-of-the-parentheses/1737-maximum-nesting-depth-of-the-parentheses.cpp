class Solution {
public:
    int maxDepth(string s) {
        int maxD = 0;
        int count = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                count++;
                maxD = max(maxD, count);
            } else if (s[i] == ')') {
                count--;
            }
        }
        return maxD;
    }
};