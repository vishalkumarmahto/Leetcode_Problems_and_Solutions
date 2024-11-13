class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> a, b;
        vector<vector<long long int>> dp1(40), dp2(40);
        long long int sum1 = 0, sum2 = 0;
        for (int i = 0; i < n; i++) {
            if (i < n / 2)
                a.push_back(nums[i]), sum1 += nums[i];
            else
                b.push_back(nums[i]), sum2 += nums[i];
        }
        n = n / 2;
        unordered_map<long long int, int> m1, m2;
        vector<long long int> v1, v2;
        for (int i = 0; i < (int)(1 << n); i++) {
            long long int sum1 = 0, sum2 = 0;
            int sets = 0;
            for (int j = 0; j < n; j++) {
                if ((i & (1 << j))) {
                    sets++;
                    sum1 += a[j];
                }
            }
            dp1[sets].push_back(sum1);
        }
        for (int i = 0; i < (int)(1 << n); i++) {
            long long int sum2 = 0, sum1 = 0;
            int sets = 0;
            for (int j = 0; j < n; j++) {
                if ((i & (1 << j))) {
                    sets++;
                    sum1 += b[j];
                }
            }
            dp2[sets].push_back(sum1);
        }
        long long int ans = LLONG_MAX;
        for (int i = 0; i <= n; i++) {
            int sets = i;
            int nonsets = n - i;
            sort(dp2[nonsets].begin(), dp2[nonsets].end());
            for (auto i : dp1[sets]) {
                long long currSum = (sum1 + sum2 - 2 * i) / 2;
                int loc = lower_bound(dp2[nonsets].begin(), dp2[nonsets].end(),
                                      currSum) -
                          dp2[nonsets].begin();
                if (loc != dp2[nonsets].size())
                    ans = min(ans,
                              abs(sum1 + sum2 - 2 * i - 2 * dp2[nonsets][loc]));
                if (loc > 0)
                    ans = min(ans, abs(sum1 + sum2 - 2 * i -
                                       2 * dp2[nonsets][loc - 1]));
                if (loc + 1 < dp2[nonsets].size())
                    ans = min(ans, abs(sum1 + sum2 - 2 * i -
                                       2 * dp2[nonsets][loc + 1]));
            }
        }
        return ans;
    }
};