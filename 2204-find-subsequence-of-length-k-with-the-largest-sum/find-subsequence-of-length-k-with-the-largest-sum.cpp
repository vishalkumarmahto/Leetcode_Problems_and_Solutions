class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();
        vector<pair<int, int>> arr;
        for (int i = 0; i < n; i++) {
            arr.emplace_back(i, nums[i]);
        }
        sort(arr.begin(), arr.end(),
             [&](auto x1, auto x2) { return x1.second > x2.second; });
        sort(arr.begin(), arr.begin() + k);
        vector<int> res;
        for (int i = 0; i < k; i++) {
            res.push_back(arr[i].second);
        }
        return res;
    }
};