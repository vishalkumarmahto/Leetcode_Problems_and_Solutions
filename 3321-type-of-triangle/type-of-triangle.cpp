class Solution {
public:
    string triangleType(vector<int>& nums) {
        int i = 0;
        if (nums[i] + nums[i + 1] > nums[i + 2] &&
            nums[i] + nums[i + 2] > nums[i + 1] &&
            nums[i + 1] + nums[i + 2] > nums[i]) {

            if (nums[i] == nums[i + 1] && nums[i + 1] == nums[i + 2])
                return "equilateral";

            else if (nums[i] == nums[i + 1] || nums[i + 1] == nums[i + 2] ||
                     nums[i + 2] == nums[i])
                return "isosceles";
            else
                return "scalene";
        }
        else return "none";
    }
};