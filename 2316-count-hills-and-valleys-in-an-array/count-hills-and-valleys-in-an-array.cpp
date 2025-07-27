class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        int i = 0;
        int j = 1;
        while (j + 1 < n) {
            if((nums[j]>nums[i]&&nums[j]>nums[j+1])
            || (nums[j]<nums[i]&&nums[j+1]>nums[j])){
                cnt++;
                i = j;
            }
            j++;
        }
        return cnt;
    }
};