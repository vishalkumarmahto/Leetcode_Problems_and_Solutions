class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        unordered_map<int, int> mpp;
        sort(nums.begin(), nums.end());
        int res = -1;
        for (int num : nums) {
            int _sqrt = sqrt(num);
            if (_sqrt * _sqrt == num && mpp.find(_sqrt) != mpp.end()) {
                mpp[num] = mpp[_sqrt] + 1;
                res = max(res, mpp[num]);
            } else
                mpp[num] = 1;
        }
        return res;
    }
};