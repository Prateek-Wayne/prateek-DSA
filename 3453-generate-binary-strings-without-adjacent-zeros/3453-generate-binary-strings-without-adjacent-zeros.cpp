class Solution {
public:
    void helper(string s,int n,vector<string> &ans)
    {
        if(s.length()==n)
        {
            ans.push_back(s);
            return;
        }
        // 
        int i=s.length();
        if(s[i-1]=='0')
        {
            s+='1';
            helper(s,n,ans);
            s.pop_back();
        }
        else if(s[i-1]=='1')
        {
            s+='0';
            helper(s,n,ans);
            s.pop_back();
            s+='1';
            helper(s,n,ans);
            s.pop_back();
        }
    }
    vector<string> validStrings(int n) {
        vector<string> ans;
        helper("0",n,ans);
        helper("1",n,ans);
        return ans;
    }
};