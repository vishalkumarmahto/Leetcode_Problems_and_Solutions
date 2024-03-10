class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        unordered_map<int, int> mpp;
        for (auto it : nums1) {
            mpp[it]++;
        }
        for (auto it : nums2) {
            if (mpp.find(it) != mpp.end()) {
                result.push_back(it);
                mpp.erase(it);
            }
        }
        return result;
    }
};