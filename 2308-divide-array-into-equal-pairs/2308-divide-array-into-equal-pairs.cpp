class Solution {
public:
    bool divideArray(vector<int>& nums) {
        map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }
        int n = nums.size() / 2;

        if (mp.size() > n)
            return false;
        int count = 0;
        for (auto i : mp) {
            count += (i.second / 2);
        }
        if (count == n)
            return true;
        return false;
    }
};