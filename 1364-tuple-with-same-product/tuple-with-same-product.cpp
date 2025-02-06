class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mpp;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int prod = nums[i] * nums[j];
                mpp[prod]++;
            }
        }
        int result = 0;
        for (auto it : mpp) {
            int count = it.second;
            if (count > 1) {
                result += count * (count - 1) * 4;
            }
        }
        return result;
    }
};