class Solution {


public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(4+1, 0));
       
        for (int ind = n - 1; ind >= 0; ind--) {
            for (int trans = 3; trans >= 0; trans--) {
                int profit = 0;
               if (trans % 2 == 0) { // Buy
                    profit = max(-prices[ind] + dp[ind + 1][trans + 1], 
                                 0 + dp[ind + 1][trans]); // Skip
                } else { // Sell
                    profit = max(prices[ind] +  dp[ind + 1][trans + 1], 
                                 0 + dp[ind + 1][trans]); // Skip
                }
                dp[ind][trans] = profit;
            }
        }
        return dp[0][0];
    }
};