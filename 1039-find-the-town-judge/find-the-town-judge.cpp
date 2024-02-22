class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> trusting(n + 1, 0);
        vector<int> trusted(n + 1, 0);
        for (auto it : trust) {
            trusting[it[0]]++;
            trusted[it[1]]++;
        }
        int ans = -1;
        for (int i = 1; i <= n; i++) {
            if (trusting[i] == 0 && trusted[i] == n - 1) {
                ans = i;
            }
        }

        return ans;
    }
};