class Solution {
public:
    vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int solve(int row, int col, vector<vector<int>>& grid, int n, int m) {
        int res = grid[row][col], curr = grid[row][col];
        grid[row][col] = 0;
        for (int i = 0; i < 4; ++i) {
            int newRow = row + dir[i].first;
            int newCol = col + dir[i].second;
            if (newRow >= 0 and newRow < n and newCol >= 0 and newCol < m and
                grid[newRow][newCol]) {
                res = max(res, curr + solve(newRow, newCol, grid, n, m));
            }
        }
        grid[row][col] = curr;
        return res;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int res = 0, n = size(grid), m = size(grid[0]);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j]) {
                    res = max(res, solve(i, j, grid, n, m));
                }
            }
        }
        return res;
    }
};