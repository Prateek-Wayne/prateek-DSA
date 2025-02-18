class Solution {
public:
    int findMax(vector<int> arr) {
        int maxy = INT_MIN;
        for (int i = 0; i < arr.size(); i++) {
            maxy = max(maxy, arr[i]);
        }
        return maxy;
    }

    bool countBouque(vector<int>& bloomDay, int days, int k, int m) {
        int ans = 0, count = 0;
        for (int i = 0; i < bloomDay.size(); i++) {
            if (bloomDay[i] <= days)
                count++;
            else {
                ans += (count / k);
                count = 0;
            }
        }
        ans += count / k;
        if (ans >= m)
            return true;
        return false;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
     if ((long) m * k > bloomDay.size()) {
            return -1;
        }
        int low = 1, high = findMax(bloomDay);
        while (low <= high) {
            int mid = low + (high - low) / 2;
            bool boque = countBouque(bloomDay, mid, k, m);
            if (boque) {
                high = mid - 1;
            } else
                low = mid + 1;
        }
        return low;
    }
};