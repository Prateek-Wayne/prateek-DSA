class Solution {
public:
    int numberOfSubstrings(string s) {
        int a=-1;
        int b=-1;
        int c=-1;
        int ans=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='a')
                a=i;
            else if(s[i]=='b')
                b=i;
            else if(s[i]=='c')
                c=i;
            ans+=1+min(a,min(b,c));
        }
        return ans;
    }
};