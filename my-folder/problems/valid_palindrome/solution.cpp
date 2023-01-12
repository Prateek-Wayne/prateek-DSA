class Solution {
public:
    
bool isPalindrome(string &s)
{
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    string n = "";
    for (auto i : s)
    {
        if (isalpha(i)||isdigit(i))
        {
            n += i;
        }
    }
    int first = 0;
    int last = n.size() - 1;

    while (first <= last)
    {
        if (n[first] != n[last])
            return false;
        first++;
        last--;
    }
    return true;
}
};