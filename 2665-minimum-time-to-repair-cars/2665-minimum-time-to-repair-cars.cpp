class Solution {
public:
    bool calculate(vector<int>& ranks, long long time, int cars) {
        long long totalCars = 0;
        for (int i = 0; i < ranks.size(); i++) {
            totalCars += sqrt((1.0 * time) / ranks[i]);
            if (totalCars >= cars)
                return true;
        }
        return false;
    }
    long long repairCars(vector<int>& ranks, int cars) {
        long long minTime = LLONG_MAX;
        long long low = 1;
        long long high = *max_element(ranks.begin(), ranks.end()) *1LL * cars * cars;
        while (low <= high) {
            long long mid = (low) + (high - low) / 2;
            if (calculate(ranks, mid, cars)) {
                minTime = min(minTime, mid);
                high = mid - 1;
            } else
                low = mid + 1;
        }
        return minTime;
    }
};