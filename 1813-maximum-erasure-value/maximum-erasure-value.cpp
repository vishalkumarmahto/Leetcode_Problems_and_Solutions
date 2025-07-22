class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> seen;
        int left = 0;
        int currSum = 0;
        int maxSum = 0;
        for (int right = 0; right < n; right++) {
            while (seen.find(nums[right]) != seen.end()) {
                currSum -= nums[left];
                seen.erase(nums[left]);
                left++;
            }
            currSum += nums[right];
            seen.insert(nums[right]);
            maxSum = max(maxSum, currSum);
        }
        return maxSum;
    }
};