class Solution {


public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<int>after(2*k+1,0),curi(2*k+1,0);
        for (int ind = n - 1; ind >= 0; ind--) {
            for (int trans = 2 * k - 1; trans >= 0; trans--) {
                if (trans % 2 == 0) {
                    curi[trans] = max(-prices[ind] + after[trans + 1],
                                         0 + after[trans]);
                } else {
                    curi[trans] = max(prices[ind] + after[trans + 1],
                                         0 + after[trans]);
                }
            }
            after = curi;
        }
        return curi[0];
    }
};