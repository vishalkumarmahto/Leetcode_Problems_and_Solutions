class Solution {
public:
    int longestConsecutive(vector<int>& arr) {
        map<int, int> mpp;
        for (int i : arr) {
            mpp[i] = i;
        }
        int count = 1;
        int maxi = 0;
        for (auto it : mpp) {
            if (mpp.find(it.first + 1) != mpp.end()) {
                count++;
            }

            else {
                maxi = max(maxi, count);
                count = 1;
            }
        }
        return maxi;
    }
};