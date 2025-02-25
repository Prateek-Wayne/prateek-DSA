class Solution {
public:
    int myAtoi(string s) {
        string resultant = "";
        int trailingSpaces = 0;
        while (s[0] == ' ')
            s.erase(0, 1);
        bool positive = true;
        long long ans = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '-' && i == 0) {
                positive = false;
                continue;
            }
            if (s[i] == '+' && i == 0) {
                positive = true;
                continue;
            }
            int number = s[i] - '0';
            if (number >= 0 && number <= 9) {
                ans = ans * 10 + number;
                if (ans > INT_MAX && !positive)
                    return INT_MIN;
                else if (ans > INT_MAX && positive)
                    return INT_MAX;
            } else
                break;
        }
        return positive ? ans : (-1 * ans);
    }
};