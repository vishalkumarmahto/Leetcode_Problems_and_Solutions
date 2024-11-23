class Solution {
private:
    int f(int ind, int trans, vector<int>& prices, vector<vector<int>>& dp) {
        if (ind == prices.size() || trans == 4)
            return 0;
        int profit = 0;
        if (dp[ind][trans] != -1)
            return dp[ind][trans];
        if (trans % 2 == 0) // buy
        {
            profit = max(-prices[ind] + f(ind + 1, trans + 1, prices, dp),
                         0 + f(ind + 1, trans, prices, dp));

        } else {
            profit = max(prices[ind] + f(ind + 1, trans + 1, prices, dp),
                         0 + f(ind + 1, trans, prices, dp));
        }
        return dp[ind][trans] = profit;
    }

public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int>after(4,0),curi(4,0);
       
        for (int ind = n - 1; ind >= 0; ind--) {
            for (int trans = 3; trans >= 0; trans--) {
                int profit = 0;
               if (trans % 2 == 0) { // Buy
                    profit = max(-prices[ind] + ((trans + 1 <= 3) ? after[trans + 1] : 0), 
                                 0 + after[trans]); // Skip
                } else { // Sell
                    profit = max(prices[ind] + ((trans + 1 <= 3) ? after[trans + 1] : 0), 
                                 0 + after[trans]); // Skip
                }
                curi[trans] = profit;
            }
            after = curi;
        }
        return after[0];
    }
};