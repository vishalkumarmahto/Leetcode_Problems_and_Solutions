class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<pair<int, int>, int>> q;
        int freshOranges = 0;
        
        // Initialize queue with all rotten oranges and count fresh oranges.
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                } else if (grid[i][j] == 1) {
                    freshOranges++;
                }
            }
        }

        // Early exit if there are no fresh oranges to start with.
        if (freshOranges == 0) return 0;

        int tm = 0;
        int drow[] = {-1, 0, +1, 0};
        int dcol[] = {0, 1, 0, -1};
        
        // BFS traversal to rot adjacent fresh oranges.
        while (!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();
            tm = max(tm, t);

            for (int i = 0; i < 4; i++) {
                int nrow = r + drow[i];
                int ncol = c + dcol[i];
                
                // If adjacent cell has a fresh orange, rot it and add to queue.
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1) {
                    grid[nrow][ncol] = 2;
                    q.push({{nrow, ncol}, t + 1});
                    freshOranges--;
                }
            }
        }

        // If there are fresh oranges left, return -1; otherwise, return time.
        return freshOranges == 0 ? tm : -1;
    }
};
