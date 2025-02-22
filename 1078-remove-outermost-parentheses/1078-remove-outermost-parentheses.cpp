class Solution {
public:

string removeOuterParentheses(string s)
{
    int n = s.size();
    int i = 0;
    int count = 0;
    string ans = "";
    while (i < n)
    {
        if (s[i] == '(' && count == 0)
        {
            count = 1;
            i++;
            continue;
        }
        string temp;
        while (count)
        {
            if (s[i] == '(')
                count++;
            else
                count--;
             if (count != 0) temp.push_back(s[i]);
            i++;
        }
        ans += temp;
        count = 0;
    }
    return ans;
}
};