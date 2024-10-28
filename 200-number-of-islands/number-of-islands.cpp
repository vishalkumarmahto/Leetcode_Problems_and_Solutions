class Solution {
public:
    void bfs(int row, int col, vector<vector<char>>& grid,
             vector<vector<int>>& vis) {
        vis[row][col] = 1;
        queue<pair<int, int>> q;
        q.push({row, col});
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while (!q.empty()) {
            int n = grid.size();
            int m = grid[0].size();

            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for (auto& dir : directions) {
                int nrow = r + dir.first;
                int ncol = c + dir.second;
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                    grid[nrow][ncol] == '1' && !vis[nrow][ncol]) {
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
    }
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j] == '1') {
                    cnt++;
                    bfs(i, j, grid, vis);
                }
            }
        }
        return cnt;
    }
};