class Solution {
public:
    string getEncryptedString(string s, int k) {
        string temp=s;
        for(int i=0;i<s.length();i++)
        {
            temp[i]=s[(i+k)%s.length()];
        }
        return temp;
    }
};