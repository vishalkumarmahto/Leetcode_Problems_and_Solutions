class Solution {
public:
    int climbStairs(int n) {
        int dp0=1,dp1=1,dp;
        for(int i=2;i<=n;i++){
            dp = dp0+dp1;
            dp0=dp1;
            dp1=dp;
        }
        return dp1;
    }
};