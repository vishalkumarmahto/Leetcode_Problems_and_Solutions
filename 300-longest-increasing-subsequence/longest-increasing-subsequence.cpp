class Solution {
public:
    int lengthOfLIS(vector<int>& arr) {
        int n = arr.size();
        int maxi = 1;
        vector<int> dp(n, 1);
        for (int ind = 0; ind < n; ind++) {
            for (int prev = 0; prev < ind; prev++) {
                if (arr[prev] < arr[ind])
                    dp[ind] = max(1 + dp[prev], dp[ind]);
            }
            maxi = max(maxi, dp[ind]);
        }
        return maxi;
    }
};