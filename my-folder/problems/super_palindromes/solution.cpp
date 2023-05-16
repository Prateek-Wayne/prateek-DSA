class Solution {
public:
    bool check(long long num) {
    string S = to_string(num);
    string P = S;
    reverse(P.begin(), P.end());
    if (S == P)
        return true;
    return false;
}
    
    int superpalindromesInRange(string left, string right) {
       
        long long l=stoll(left);
        long long r=stoll(right);
        vector<long long > ans;
        for(int i=1;i<10;i++)
        {
            ans.push_back(i);
        }
        for(int i=1;i<1e4;i++)
        {
            string s1=to_string(i);
            string s2=s1;
            reverse(s2.begin(),s2.end());
            ans.push_back(stoll(s1+s2));
            for(int i=0;i<10;i++)
            {
                string temp;
                temp=s1+to_string(i)+s2;
                ans.push_back(stoll(temp));
            }
        }
        int count=0;
        for(auto i:ans)
        {   
            long long num=i*i;
            if(num>=l and num<=r and check(num))
                count++;
        }
        return count;
        
        
        
    }
};