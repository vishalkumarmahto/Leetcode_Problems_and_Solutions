class Solution {
public:
    int lcs(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        vector<int>prev(m+1,0),curi(m+1,0);
     
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s1[i - 1] == s2[j - 1])
                   curi[j] = 1 +prev[j - 1];
                else
                    curi[j] = max(prev[j], curi[j - 1]);
            }
            prev = curi;
        }
        return prev[m];
    }
    int longestPalindromeSubseq(string s) {
        string t = s;
        reverse(t.begin(), t.end());
        return lcs(s, t);
    }
};