class Solution {
public:
  
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<long long>> dp(n, vector<long long>(amount + 1, 0)); // Use long long for safety

        // Base case: If the target is 0, there is exactly 1 way (use no coins)
        for (int tar = 0; tar <= amount; tar++) {
            if (tar % coins[0] == 0)
                dp[0][tar] = 1; // Use one type of coin repeatedly
        }

        // Fill the DP table
        for (int ind = 1; ind < n; ind++) {
            for (int tar = 0; tar <= amount; tar++) {
                long long notTake = dp[ind - 1][tar]; // Do not include the current coin
                long long take = 0;
                if (coins[ind] <= tar) // Include the current coin
                    take = dp[ind][tar - coins[ind]];
                dp[ind][tar] = take + notTake;

                // Avoid potential overflow issues
                if (dp[ind][tar] > INT_MAX)
                    dp[ind][tar] = INT_MAX;
            }
        }

        return dp[n - 1][amount] > INT_MAX ? -1 : dp[n - 1][amount];
    }
};