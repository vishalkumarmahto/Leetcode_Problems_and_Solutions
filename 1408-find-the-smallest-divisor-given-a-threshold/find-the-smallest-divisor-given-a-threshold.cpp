class Solution {
public:
    int sumOfDiv(vector<int>& nums, int day, int threshold) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += ceil((double)nums[i] / (double)day);
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1, high = *max_element(nums.begin(), nums.end());
        while (low <= high) {
            int mid = (low + high) / 2;
            if (sumOfDiv(nums, mid, threshold) <= threshold) {
                high = mid - 1;
            } else
                low = mid + 1;
        }
        return low;
    }
};