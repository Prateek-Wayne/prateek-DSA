class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        // int n=stoi(word);
        int n=word.length();
        vector<int> ans(n,0);
        long long prev=0;
        for(int i=0;i<n;i++)
        {
             prev=(prev*10+(word[i]-'0'))%m;
            if(prev==0)
                ans[i]=1;
        }
        return ans;
    }
    
};