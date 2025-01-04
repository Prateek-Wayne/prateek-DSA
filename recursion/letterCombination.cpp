#include <bits/stdc++.h>
using namespace std;

void helper(string arr1, string arr2, int ind1, string ds, vector<string> &ans)
{
    if (ind1 < 0)
    {
        // Base case: when all characters in arr1 have been processed
        return;
    }

    for (int ind2 = 0; ind2 < arr2.size(); ind2++)
    {
        string s = "";
        s += arr1[ind1];  // Add the current character from arr1
        s += arr2[ind2];  // Add the current character from arr2
        ans.push_back(s); // Store the combination
    }

    // Recursive call to process the next character in arr1
    helper(arr1, arr2, ind1 - 1, ds, ans);
}

vector<string> letterCombinations(string digits)
{

    vector<string> ans;
    map<char, string>
        keyPad = {
            {'1', ""},
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}};
    if (digits.length()==1)
    {
        ans=help
    }
    // helper()
}
int main()
{
    vector<string> ans;
    helper("abc", "def", 2, "", ans);
    for (auto i : ans)
        cout << i << endl;
    return 0;
}