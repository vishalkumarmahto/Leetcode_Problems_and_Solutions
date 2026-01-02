class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mpp;
        for (int num : nums) {
            mpp[num]++;
        }
        int maxi = 0;
        int ans = -1;
        for (auto it : mpp) {
            if (it.second > maxi) {

                maxi = it.second;
                ans = it.first;
            }
        }
        return ans;
    }
};