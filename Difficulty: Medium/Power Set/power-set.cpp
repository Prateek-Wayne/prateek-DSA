//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	
void helper(string s,string ds,vector<string> & ans,int ind)
{
    //  base condition...
    if(ind==(s.size()))
        {  
            if(ds.size()!=0)
                ans.push_back(ds);
            return ;
        }
    // tick condition...
    ds.push_back(s[ind]);
    helper(s,ds,ans,ind+1);

    // drop condition...
    ds.pop_back();
    helper(s,ds,ans,ind+1);

    
}
		vector<string> AllPossibleStrings(string s){
		     vector<string> ans;
    helper(s, "", ans, 0);
    sort(ans.begin(), ans.end());

    return ans;
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends