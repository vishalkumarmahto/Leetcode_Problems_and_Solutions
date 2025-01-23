class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> rowCounts(m, 0), colCounts(n, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j]) {
                    rowCounts[j]++;
                    colCounts[i]++;
                }
            }
        }
        int serverCounts = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j]) {
                    serverCounts += rowCounts[j] > 1 || colCounts[i] > 1;
                }
            }
        }
        return serverCounts;
    }
};