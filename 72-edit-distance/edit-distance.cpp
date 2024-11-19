class Solution {
public:
    int minDistance(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        vector<int>prev(m+1,0),curi(m+1,0);
        for (int j = 0; j <= m; j++) prev[j] = j;
        for (int i = 1; i <= n; i++) {
            curi[0] = i;
            for (int j = 1; j <= m; j++) {
                if (s1[i - 1] == s2[j - 1])
                    curi[j] = 0 + prev[j - 1];
                else
                    curi[j] = min(1 + curi[j - 1],
                                   min(1 + prev[j], 1 + prev[j - 1]));
            }
            prev = curi;
        }
        return prev[m];
    }
};