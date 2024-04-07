class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size();
        int dp[2][102] = {0}; // reduced space
        dp[n & 1][0] = 1;     // base case
        for (int i = n - 1; i >= 0; i--) {
            char c = s[i];
            for (int balance = 0; balance <= n; balance++) {
                int ans = 0;
                switch (c) {
                case '(':
                    ans = dp[(i + 1) & 1][balance + 1];
                    break;
                case ')':
                    if (balance > 0)
                        ans = dp[(i + 1) & 1][balance - 1];
                    break;
                case '*':
                    ans |= dp[(i + 1) & 1][balance + 1] ||
                           dp[(i + 1) & 1][balance];
                    if (balance > 0)
                        ans |= dp[(i + 1) & 1][balance - 1];
                }
                dp[i & 1][balance] = ans;
            }
        }
        return dp[0][0] == 1;
    }
};