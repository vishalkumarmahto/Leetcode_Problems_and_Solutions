class Solution {
private:
    int f(int ind, int trans, int k, vector<int>& prices,
          vector<vector<int>>& dp) {
        if (ind == prices.size() || trans == 2 * k)
            return 0;
        if (dp[ind][trans] != -1)
            return dp[ind][trans];
        if (trans % 2 == 0) {
            return dp[ind][trans] =
                       max(-prices[ind] + f(ind + 1, trans + 1, k, prices, dp),
                           0 + f(ind + 1, trans, k, prices, dp));
        } else {
            return dp[ind][trans] =
                       max(prices[ind] + f(ind + 1, trans + 1, k, prices, dp),
                           0 + f(ind + 1, trans, k, prices, dp));
        }
    }

public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2 * k + 1, 0));
        for (int ind = n - 1; ind >= 0; ind--) {
            for (int trans = 2 * k - 1; trans >= 0; trans--) {
                if (trans % 2 == 0) {
                    dp[ind][trans] = max(-prices[ind] + dp[ind + 1][trans + 1],
                                         0 + dp[ind + 1][trans]);
                } else {
                    dp[ind][trans] = max(prices[ind] + dp[ind + 1][trans + 1],
                                         0 + dp[ind + 1][trans]);
                }
            }
        }
        return dp[0][0];
    }
};