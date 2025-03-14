class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int low = 1;
        int high = *max_element(candies.begin(), candies.end());
        int result=0;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long count = 0;
            for (int i = 0; i < candies.size(); i++) {
                count += (candies[i]) / mid;
            }
            if (count >= k){
                result=mid;
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
        return result;
    }
};