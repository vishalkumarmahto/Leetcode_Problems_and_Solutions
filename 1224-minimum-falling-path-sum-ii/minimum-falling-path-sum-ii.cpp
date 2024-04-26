class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        for (int i = 1; i < grid.size(); i++) {
            int min1 = INT_MAX;
            int ind1 = -1;
            for (int j = 0; j < grid[0].size(); j++) {
                if (min1 > grid[i - 1][j]) {
                    min1 = grid[i - 1][j];
                    ind1 = j;
                }
            }
            int min2 = INT_MAX;
            for (int j = 0; j < grid[0].size(); j++) {
                if (j != ind1 && min2 > grid[i - 1][j]) {
                    min2 = grid[i - 1][j];
                }
            }
            for (int j = 0; j < grid[0].size(); j++) {
                grid[i][j] += (j != ind1) ? min1 : min2;
            }
        }
        return *min_element(grid[grid.size() - 1].begin(),
                            grid[grid.size() - 1].end());
    }
};