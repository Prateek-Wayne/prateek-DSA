class Solution {
public:

int findTheLongestSubstring(string s)
{
    map<string, int> mp;
    vector<int> vowels(5, 0);
    int ans = 0;
    mp["00000"]=-1;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == 'a')
        {
            vowels[0] = (vowels[0] + 1) % 2;
        }
        else if (s[i] == 'e')
        {
            vowels[1] = (vowels[1] + 1) % 2;
        }
        else if (s[i] == 'i')
        {
            vowels[2] = (vowels[2] + 1) % 2;
        }
        else if (s[i] == 'o')
        {
            vowels[3] = (vowels[3] + 1) % 2;
        }
        else if (s[i] == 'u')
        {
            vowels[4] = (vowels[4] + 1) % 2;
        }
        string vowelstring = "";
        for (int v = 0; v < vowels.size(); v++)
        {
            vowelstring += to_string(vowels[v]);
        }
        if (mp.count(vowelstring))
        {
            ans = max(ans, i - mp[vowelstring]);
            mp[vowelstring] = min(i, mp[vowelstring]);
        }
        else
        {
            mp[vowelstring] = i;
        }
    }
    return ans;
}
};