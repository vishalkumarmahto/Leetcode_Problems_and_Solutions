class Solution {
public:
    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();
        if (n < 2 || k == 0) {
            return 0;
        }

        vector<long long> previousMaxProfit(n, 0);

        for (int t = 1; t <= k; ++t) {
            vector<long long> currentMaxProfit(n, 0);
            long long bestBuyNormal = LLONG_MIN;
            long long bestBuyShort = LLONG_MIN;

            for (int i = 1; i < n; ++i) {
                long long prevProfit = (i > 1) ? previousMaxProfit[i - 2] : 0;
                bestBuyNormal = max(bestBuyNormal, prevProfit - prices[i - 1]);
                bestBuyShort = max(bestBuyShort, prevProfit + prices[i - 1]);
                long long profitToday = max(
                    static_cast<long long>(prices[i]) + bestBuyNormal,
                    static_cast<long long>(-prices[i]) + bestBuyShort
                );
                currentMaxProfit[i] = max(currentMaxProfit[i - 1], profitToday);
            }

            previousMaxProfit = currentMaxProfit;
        }

        return previousMaxProfit[n - 1];
    }
};
