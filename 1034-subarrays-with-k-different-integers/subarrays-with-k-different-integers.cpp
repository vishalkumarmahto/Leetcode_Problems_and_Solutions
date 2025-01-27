class Solution {
public:
    int countSubarrayWithAtMostKDistinct(vector<int>& nums, int k) {
        int left = 0, right = 0, cnt = 0;
        unordered_map<int,int>mpp;
        int n = nums.size();
        while (right < n) {
            mpp[nums[right]]++;
            while (mpp.size() > k) {
                mpp[nums[left]]--;
                if (mpp[nums[left]] == 0)
                    mpp.erase(nums[left]);
                left++;
            }
            cnt += right - left + 1;
            right++;
        }
        return cnt;
    }
        int subarraysWithKDistinct(vector<int> & nums, int k) {
            return countSubarrayWithAtMostKDistinct(nums, k) -
                   countSubarrayWithAtMostKDistinct(nums, k - 1);
        }
    };