class Solution {
public:
    int countGoodSubstrings(string s) {
        long long i=0,j=0;
        long long count=0;
        while(j<s.length())
        {
            if(j-i+1<3)
            {
                j++;
            }
            else if(j-i+1==3)
            {
                int temp=i;
                set<char>st;
                for(;temp<=j;temp++)
                {
                    st.insert(s[temp]);
                }
                if(st.size()==3)
                    count++;
                i++;
                j++;
            }
        }
        return count;
    }
};