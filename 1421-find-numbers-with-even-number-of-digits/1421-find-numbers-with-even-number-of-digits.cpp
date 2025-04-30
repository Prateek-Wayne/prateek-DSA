class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            int number = nums[i];
            int totaldigit = 0;
            while (number) {
                number = number / 10;
                totaldigit++;
            }
            if (!(totaldigit & 1))
                count++;
        }
        return count;
    }
};