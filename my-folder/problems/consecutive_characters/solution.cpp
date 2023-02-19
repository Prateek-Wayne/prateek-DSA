class Solution {
public:
    int maxPower(string s) {
        int maxy=0;
        int count=0;
        for(int i=1;i<s.length();i++)
        {
          if(s[i-1]==s[i])
              count++;
          else
          {
              maxy=max(maxy,count);
              count=0;
          }
        }
        maxy=max(maxy,count);
        return maxy+1;
    }
};