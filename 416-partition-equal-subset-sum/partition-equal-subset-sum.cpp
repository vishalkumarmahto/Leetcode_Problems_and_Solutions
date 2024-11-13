class Solution {
private:
    bool isSubsetSum(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        vector<bool> prev(k + 1, 0), curi(k + 1, 0);
        prev[0] = curi[0] = true;

        if (arr[0] <= k)
            prev[arr[0]] = true;
        for (int ind = 1; ind < n; ind++) {
            for (int target = 1; target <= k; target++) {

                bool notTake = prev[target];
                bool take = false;
                if (arr[ind] <= target)
                    take = prev[target - arr[ind]];

                curi[target] = take | notTake;
            }
            prev = curi;
        }
        return prev[k];
    }

public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        int sum = accumulate(nums.begin(), nums.end(), 0);
      
        if (sum % 2 == 1)
            return false;
        return isSubsetSum(nums, sum / 2);
    }
};