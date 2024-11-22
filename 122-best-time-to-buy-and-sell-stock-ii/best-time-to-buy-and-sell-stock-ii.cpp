class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> ahead(2, 0), curi(2, 0);
        ahead[0] = ahead[1] = 0;
        for (int ind = n - 1; ind >= 0; ind--) {
            for (int buy = 0; buy <= 1; buy++) {
                int profit = 0;

                if (buy) {
                    profit = max(-prices[ind] + ahead[0], 0 + ahead[1]);
                }

                else {
                    profit = max(prices[ind] + ahead[1], 0 + ahead[0]);
                }
                curi[buy] = profit;
            }
            ahead = curi;
        }
        return ahead[1];
    }
};