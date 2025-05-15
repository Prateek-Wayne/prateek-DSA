class Solution {
public:
    static vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n=groups.size(), len=1;
        for_each(words.begin()+1, words.end(), [&, i=1](auto& x) mutable{
            if(groups[i-1]!=groups[i++]) words[len++]=x;
        });
        words.resize(len);
        return words;
    }
};