class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int freq[26][26]={{0}};
        for(auto& w: words){
            const int i=w[0]-'a', j=w[1]-'a';
            freq[i][j]++;
        }
        int pal=0;
        bool hasDouble=0;
        for(int i=0; i<26; i++){
            const int fi=freq[i][i];
            pal+=fi/2*4;
            if (hasDouble==0 && (fi&1)==1)
                hasDouble=1;
        }
        pal+=hasDouble*2;
        for(int i=0; i<26; i++)
            for(int j=i+1; j<26; j++)
                pal+=min(freq[i][j], freq[j][i])*4;
        return pal;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();