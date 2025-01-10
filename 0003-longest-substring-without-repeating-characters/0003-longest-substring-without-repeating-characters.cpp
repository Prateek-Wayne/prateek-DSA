class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        set<int> st;
        int i = 0;
        int j = 0;
        int n = s.length();
        int maxy = 0;
        while (j < n) {
            auto it = st.find(s[j]);
            while (it != st.end() && !st.empty()) {
                st.erase(s[i]);
                i++;
                it = st.find(s[j]);
            }
            maxy = max(maxy, j - i + 1);
            st.insert(s[j]);
            j++;
        }
        return maxy;
    }
};