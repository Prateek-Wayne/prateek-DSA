class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        string str = "";
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                if (!str.empty()) {
                    st.push(str);
                    str = "";
                }
            } else
                str += s[i];
        }
        if (!str.empty())
            st.push(str);
        string ans = "";
        while (st.size() != 1) {
            ans += st.top() + " ";
            st.pop();
        }
        ans += st.top();
        return ans;
    }
};