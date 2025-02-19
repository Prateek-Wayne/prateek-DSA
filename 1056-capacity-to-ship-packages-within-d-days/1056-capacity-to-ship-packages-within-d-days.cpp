class Solution {
public:
    int calculateTotalDays(vector<int>& weights, int capacity) {
        int days = 1;
        int load = 0;
        for (int i = 0; i < weights.size(); i++) {
            if (load + weights[i] > capacity) {
                days = days + 1;
                load = weights[i];
            } else
                load += weights[i];
        }
        return days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low = INT_MIN, high = 0;
        for (auto i : weights) {
            low = max(low, i);
            high += i;
        }
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (calculateTotalDays(weights, mid) <= days) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};