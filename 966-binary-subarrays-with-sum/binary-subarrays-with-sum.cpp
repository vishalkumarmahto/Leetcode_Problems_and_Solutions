class Solution{ 
public:
    int countSubarray(vector<int>& nums, int goal) {
        int left = 0, right = 0, sum = 0, cnt = 0;

        while (right < nums.size()) {
            sum += nums[right];

            // Shrink the window if the sum exceeds the goal
            while (sum > goal && left <= right) {
                sum -= nums[left];
                left++;
            }

            // Count subarrays with sum equal to or less than the goal
            cnt += (right - left + 1);
            right++;
        }

        return cnt;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        // Subarrays with sum exactly equal to `goal`:
        return countSubarray(nums, goal) - countSubarray(nums, goal - 1);
    }
    };