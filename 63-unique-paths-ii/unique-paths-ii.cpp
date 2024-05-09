class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
          int m=obstacleGrid.size(),n=obstacleGrid[0].size();
        if(obstacleGrid[0][0]==1||obstacleGrid[m-1][n-1]==1)return 0;
        vector<int>dp(n);
        dp[0]=1;
        for(int i=1;i<n;i++){
            dp[i]=(obstacleGrid[0][i]^1)&dp[i-1];
        }
        for(int i=1;i<m;i++){
            int prev=0;
            for(int j=0;j<n;j++){
                if(obstacleGrid[i][j])dp[j]=0;
                else dp[j]+=prev;
                prev=dp[j];
            }
        }
       return dp[n-1];
    }
};