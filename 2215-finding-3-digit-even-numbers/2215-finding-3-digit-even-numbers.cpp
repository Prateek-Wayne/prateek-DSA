class Solution {
public:

vector<int> findEvenNumbers(vector<int> &digits)
{
    set<int> st;
    int n = digits.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                if (i == j || i == k || j == k || digits[i] == 0)
                    continue;
                int number = digits[i] * 100 + digits[j] * 10 + digits[k];
                if (!(number & 1))
                {
                    st.insert(number);
                }
            }
        }
    }
    vector<int> ans;
    for (auto i : st)
    {
        ans.push_back(i);
    }
    return ans;
}
};