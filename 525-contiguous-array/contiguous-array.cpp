class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> mpp;
        int sum = 0;
        int longestSubarr = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i] == 0 ? -1 : 1;
            if (sum == 0) {
                longestSubarr = i + 1;
            } else if (mpp.find(sum) != mpp.end()) {
                longestSubarr = max(longestSubarr, i - mpp[sum]);
            } else {
                mpp[sum] = i;
            }
        }
        return longestSubarr;
    }
};