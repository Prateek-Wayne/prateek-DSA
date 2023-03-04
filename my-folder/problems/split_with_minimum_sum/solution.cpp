class Solution {
public:
    int splitNum(int num) {
        string s= to_string(num);
        sort(s.begin(),s.end());
        string x="";
        string y="";
        for(int i=0;i<s.length();i=i+2)
        {
            x+=s[i];
        }
        for(int i=1;i<s.length();i=i+2)
        {
            y+=s[i];
        }
        int num1=stoi(x);
        int num2=stoi(y);
        return num1+num2;
        
    }
};