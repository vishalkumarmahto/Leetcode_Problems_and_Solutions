class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> mpp;
        for (int i = 0; i < nums.size(); i++) {
            mpp[nums[i]]++;
        }
        int maxFrequency = 0;
        for (auto it : mpp) {
            maxFrequency = max(maxFrequency, it.second);
        }
        int maxFreqElements = 0;
        for (auto it : mpp) {
            if (it.second == maxFrequency) {

                maxFreqElements++;
            }
        }
        int totalFrequency = maxFrequency * maxFreqElements;
        return totalFrequency;
    }
};