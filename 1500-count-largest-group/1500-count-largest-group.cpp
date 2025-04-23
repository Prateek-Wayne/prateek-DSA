class Solution {
public:
    int findSum(int n) {
        int sum = 0;
        while (n != 0) {
            sum += n % 10;
            n = n / 10;
        }
        return sum;
    }
    int countLargestGroup(int n) {
        map<int, vector<int>> mp;
        for (int i = 1; i <= n; i++) {
            int sum = findSum(i);
            mp[sum].push_back(i);
        }
        int ans = 0;
        int maxSize = 0;
        for (auto i : mp) {
            if (i.second.size() > maxSize) {
                maxSize = i.second.size();
                ans = 1;
            } else if (i.second.size() == maxSize) {
                ans++;
            }
        }
        return ans;
    }
};