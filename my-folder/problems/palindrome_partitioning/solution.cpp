class Solution {
public:
    vector<vector<string>> partition(string s) {
           vector<vector<string>> ans;
            vector<string> ds;
          recurssion(s,0,ds,ans);
        return ans;
    }
    
    void recurssion(string str,int index,vector<string> &ds,vector<vector<string>> &ans)
    {
        if(index==str.length())
        {
            ans.push_back(ds);
            return;
        }
        // looping...
        for(int i=index;i<str.length();i++)
        {
            if(isPalindrome(str,index,i))
            {
                // proceed to save substring
                ds.push_back(str.substr(index,i-index+1));
                // next recursiion call
                recurssion(str,i+1,ds,ans);
                
                // again remove saved value...
                ds.pop_back();
                
            }
            
        }

    }
    
    bool isPalindrome(string s,int start,int end)
    {   

        while(start<end)
        {
            if(s[start]==s[end])
            {
                start++;
                end--;
            }
            else
            return false;
        }
        return true;
    }
};