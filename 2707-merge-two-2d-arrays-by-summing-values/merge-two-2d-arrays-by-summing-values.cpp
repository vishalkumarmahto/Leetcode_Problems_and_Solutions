class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1,
                                    vector<vector<int>>& nums2) {

        map<int, int> mpp;
        for (auto nums : nums1) {
            mpp[nums[0]] = nums[1];
        }
        for (auto nums : nums2) {
            mpp[nums[0]] += nums[1];
        }
        vector<vector<int>> mergedArray;
        for (auto it : mpp) {
            mergedArray.push_back({it.first, it.second});
        }
        return mergedArray;
    }
};