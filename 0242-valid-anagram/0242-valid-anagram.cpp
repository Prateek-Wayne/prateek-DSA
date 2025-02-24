class Solution {
public:
bool isAnagram(string s, string t)
{
    if (s.length() != t.length())
        return false;
    vector<int> track(26, 0);
    for (int i = 0; i < s.length(); i++)
    {
        track[s[i] - 'a']++;
        track[t[i] - 'a']--;
    }
    for (int i = 0; i < 26; i++)
    {
        if (track[i] != 0)
            return false;
    }
    return true;
}
};