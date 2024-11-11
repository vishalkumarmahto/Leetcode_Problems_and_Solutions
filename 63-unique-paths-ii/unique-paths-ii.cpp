class Solution {
    private:
     int uniquePath(int i, int j, vector<vector<int>>&obstacleGrid, vector<vector<int>>&dp){
        if(i>=0 && j>=0 && obstacleGrid[i][j]==1) return 0;
        if(i==0&&j==0) return 1;
        if(i<0||j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int up = uniquePath(i-1,j,obstacleGrid,dp);
        int left = uniquePath(i,j-1,obstacleGrid,dp);
        return dp[i][j] = up + left;
     }

public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return uniquePath(n-1,m-1,obstacleGrid,dp);

    }
};