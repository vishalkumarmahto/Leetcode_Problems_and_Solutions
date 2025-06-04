class Solution {
public:
    bool isMatch(string s, string p) {
          int s_len = s.length();
        int p_len = p.length();

        // dp[i][j] will be true if s[0...i-1] matches p[0...j-1]
        // +1 to account for empty string/pattern
        std::vector<std::vector<bool>> dp(s_len + 1, std::vector<bool>(p_len + 1, false));

        // Base Case: Empty string matches empty pattern
        dp[0][0] = true;

        // Base Case: Handle patterns like a*, a*b*, .* that match empty string s
        // dp[0][j] can be true only if p[j-1] is '*' and dp[0][j-2] was true
        for (int j = 1; j <= p_len; ++j) {
            if (p[j - 1] == '*') {
                // If '*' matches zero occurrences of the preceding element p[j-2]
                dp[0][j] = dp[0][j - 2];
            }
        }

        // Fill the DP table
        for (int i = 1; i <= s_len; ++i) {
            for (int j = 1; j <= p_len; ++j) {
                char s_char = s[i - 1]; // Current character in s
                char p_char = p[j - 1]; // Current character in p

                if (p_char == '.') {
                    // '.' matches any single character
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (p_char == '*') {
                    // '*' implies there's a preceding character p[j-2]
                    // Case 1: '*' matches zero occurrences of p[j-2]
                    // We check if s[0...i-1] matches p[0...j-3]
                    dp[i][j] = dp[i][j - 2];

                    // Case 2: '*' matches one or more occurrences of p[j-2]
                    // This is possible if s_char matches p[j-2] (or p[j-2] is '.')
                    if (p[j - 2] == '.' || p[j - 2] == s_char) {
                        // If it matches, we can consume s_char using p[j-2]*
                        // and check if s[0...i-2] matches the current pattern p[0...j-1]
                        dp[i][j] = dp[i][j] || dp[i - 1][j];
                    }
                } else { // p_char is a regular character ('a'-'z')
                    // If current characters match, check if previous parts matched
                    if (s_char == p_char) {
                        dp[i][j] = dp[i - 1][j - 1];
                    } else {
                        // Characters don't match, so no match
                        dp[i][j] = false;
                    }
                }
            }
        }

        return dp[s_len][p_len];
    }
};