class Solution {
public:
string triangleType(vector<int>& nums) {
    if (nums.size() != 3)
        return "invalid";
    if (nums[0] <= 0 || nums[1] <= 0 || nums[2] <= 0)
        return "none";
    
    if ((nums[0] + nums[1] > nums[2]) &&
        (nums[1] + nums[2] > nums[0]) &&
        (nums[0] + nums[2] > nums[1])) {

        if (nums[0] == nums[1] && nums[1] == nums[2])
            return "equilateral";
        else if (nums[0] == nums[1] || nums[1] == nums[2] || nums[0] == nums[2])
            return "isosceles";
        else
            return "scalene";
    }
    return "none";
}

};