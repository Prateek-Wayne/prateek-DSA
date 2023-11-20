class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        string pat="";
        map<string,int> mp;
        int i=0;
        int j=0;
        int N=s.size();
        int k=10;
        while(j<N)
        {   
            // calculation for j...
            pat+=s[j];
            if(j-i+1<k)
                j++;
            if(j-i+1==k)
            {   if(pat.size()<10)
                    pat+=s[j];
                mp[pat]++;
                // removing calculation for i..
                pat.erase(0,1);
                // iterating..
                i++;
                j++;
            }
        }
        vector<string> ans;
        for(auto i:mp)
        {
            if(i.second>1)
            {
                ans.push_back(i.first);
            }
        }
        return ans;
    }
};