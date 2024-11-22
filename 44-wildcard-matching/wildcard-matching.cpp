class Solution {
public:
    bool isMatch(string text, string pattern) {
        int n = pattern.size();
        int m = text.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));

        // Base cases
        dp[0][0] = true; // Empty pattern matches empty string

        // Pattern matches empty string only if it contains all '*'
        for (int i = 1; i <= n; i++) {
            dp[i][0] = dp[i - 1][0] && pattern[i - 1] == '*';
        }

        // Fill DP table
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (pattern[i - 1] == text[j - 1] || pattern[i - 1] == '?') {
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (pattern[i - 1] == '*') {
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1]; // '*' matches zero or more characters
                } else {
                    dp[i][j] = false;
                }
            }
        }

        return dp[n][m];
    }
};
