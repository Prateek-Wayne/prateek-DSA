class Solution {
public:
bool isValuePresent(map<char, char> myMap, char &targetValue)
{
    for (const auto &pair : myMap)
    {
        if (pair.second == targetValue)
        {
            return true;
        }
    }
    return false;
}

bool isIsomorphic(string s, string t)
{
    map<char, char> mp;
    int n = s.length();
    for (int i = 0; i < n; i++)
    {
        auto it = mp.find(s[i]);
        if (it == mp.end())
        {

            if (!isValuePresent(mp, t[i]))
            {
                mp[s[i]] = t[i];
            }
            else
                return false;
        }
        else
        {
            if (it->second != t[i])
                return false;
        }
    }
    return true;
}
};