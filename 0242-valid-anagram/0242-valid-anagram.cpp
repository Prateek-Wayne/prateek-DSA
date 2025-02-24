class Solution {
public:
bool isAnagram(string s, string t)
{
    if (s.length() != t.length())
        return false;
    vector<int> track1(26, 0);
    vector<int> track2(26, 0);
    for (int i = 0; i < s.length(); i++)
    {
        track1[s[i] - 'a']++;
    }
    for (int i = 0; i < s.length(); i++)
    {
        track2[t[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++)
    {
        if (track1[i] != track2[i])
            return false;
    }
    return true;
}
};