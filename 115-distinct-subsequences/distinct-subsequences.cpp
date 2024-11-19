class Solution {

public:
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        vector<double>prev(m+1,0),curi(m+1,0);
        prev[0]=curi[0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s[i - 1] == t[j - 1])
                    curi[j] = prev[j - 1] + prev[j];
                else
                    curi[j] = prev[j];
            }
            prev = curi;
        }
        return (int)prev[m];
    }
};