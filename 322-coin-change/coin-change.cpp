class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int>prev(amount+1,0),curi(amount+1,0);
        for (int tar = 0; tar <= amount; tar++) {
            if (tar % coins[0] == 0)
                prev[tar] = tar / coins[0];
            else
                prev[tar] = 1e9;
        }
        for (int ind = 1; ind < n; ind++) {
            for (int tar = 0; tar <= amount; tar++) {
                int notTake = 0 + prev[tar];
                int take = INT_MAX;
                if (coins[ind] <= tar)
                    take = 1 + curi[tar - coins[ind]];
                curi[tar] = min(take, notTake);
            }
            prev = curi;
        }

        int ans = prev[amount];
        if (ans >= 1e9)
            return -1;
        else
            return ans;
    }
};