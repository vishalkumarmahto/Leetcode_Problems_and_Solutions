class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mpp;
        int i = 0;
        int j = 0;
        int result = 0;

        while (j < n) {
            mpp[nums[j]]++;
            while (i < j && mpp[nums[j]] > k) {
                mpp[nums[i]]--;
                i++;
            }
            result = max(result, j - i + 1);
            j++;
        }
        return result;
    }
};