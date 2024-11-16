class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, 0));
        for (int tar = 0; tar <= amount; tar++) {
            if (tar % coins[0] == 0)
                dp[0][tar] = tar / coins[0];
            else
                dp[0][tar] = 1e9;
        }
        for (int ind = 1; ind < n; ind++) {
            for (int tar = 0; tar <= amount; tar++) {
                int notTake = 0 + dp[ind - 1][tar];
                int take = INT_MAX;
                if (coins[ind] <= tar)
                    take = 1 + dp[ind][tar - coins[ind]];
                dp[ind][tar] = min(take, notTake);
            }
        }

        int ans = dp[n - 1][amount];
        if (ans >= 1e9)
            return -1;
        else
            return ans;
    }
};