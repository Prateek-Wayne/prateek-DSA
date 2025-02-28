class Solution {
public:
    long long helper(string s, long long res, long long ind, bool positive) {
        if (ind == s.length() || ((s[ind] - '0') > 9 || (s[ind] - '0' < 0)))
            return res;
        long long num = s[ind] - '0';

        res = res * 10 + num;
        if (res > INT_MAX && !positive)
            return INT_MIN;
        if (res > INT_MAX && positive)
            return INT_MAX;

        return helper(s, res, ind + 1, positive);
    }

    int myAtoi(string s) {
        while (s[0] == ' ')
            s.erase(0, 1);
        int res = 0;
        bool positive = true;
        if (s[0] == '-' || s[0] == '+') {
            if (s[0] == '-') {
                positive = false;
                s.erase(0, 1);
            } else if (s[0] == '+') {
                positive = true;
                s.erase(0, 1);
            }
        }
        long long ans = helper(s, 0, 0, positive);
        if (ans != INT_MIN && !positive)
            ans = ans * (-1);

        // return ans % int(1e9 + 7);
        return ans;
    }
};