class Solution {
public:

string frequencySort(string s)
{
    typedef pair<char, int> p;
    map<char, int>
        mp;
    for (int i = 0; i < s.length(); i++)
        mp[s[i]]++;
    auto comp = [](p left, p right) { return left.second < right.second; };
    priority_queue<p, vector<p>, decltype(comp)> minHeap(comp);
    for (auto i : mp)
    {
        p temp;
        temp.first = i.first;
        temp.second = i.second;
        minHeap.push(temp);
    }

    s = "";
    while (!minHeap.empty())
    {
        p temp = minHeap.top();
        minHeap.pop();
        s.append(temp.second, temp.first);
    }
    return s;
}
};