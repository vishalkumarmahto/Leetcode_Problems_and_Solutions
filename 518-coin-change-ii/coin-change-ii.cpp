
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
       vector<int>prev(amount+1,0),curi(amount+1,0);
        for (int tar = 0; tar <= amount; tar++) {
            if (tar % coins[0] == 0)
                prev[tar] = 1;
            else
                prev[tar] = 0;
        }
        for (int ind = 1; ind < n; ind++) {
            for (int tar = 0; tar <= amount; tar++) {
                long long notTake = prev[tar];
                long long take = 0;
                if (coins[ind] <= tar)
                    take = curi[tar - coins[ind]];
                curi[tar] = take + notTake;
                if (curi[tar] > INT_MAX)
                    curi[tar] = INT_MAX;
            }
            prev = curi;
        }

        return prev[amount];
    }
};