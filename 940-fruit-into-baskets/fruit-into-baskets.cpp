class Solution {
public:
    int totalFruit(vector<int>& arr) {
        int n = arr.size();
        int left = 0, right = 0, maxLen = 0;
        unordered_map<int, int> mpp;
        while (right < n) {
            mpp[arr[right]]++;
            if (mpp.size() > 2) {
                mpp[arr[left]]--;
                if (mpp[arr[left]] == 0)
                    mpp.erase(arr[left]);
                left++;
            }
            if (mpp.size() <= 2) {
                maxLen = max(maxLen, right - left + 1);
            }
            right++;
        }
        return maxLen;
    }
};