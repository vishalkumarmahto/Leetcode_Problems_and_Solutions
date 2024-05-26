class Solution {
public:
    long long  dp[100004][3][4];
    long long md=1e9+7;
    long long  ans(int n,int a,int l){
        if(a>=2 or l==3) return 0;
        if(n==0) return 1;
        if(dp[n][a][l]!=-1) return dp[n][a][l];
         long long sol=ans(n-1,a,0)%md;
        sol=(sol+ans(n-1,a+1,0)%md)%md;
        sol=(sol+ans(n-1,a,l+1)%md)%md;
        return dp[n][a][l]=sol%md;
    }
    int checkRecord(int n) {
    memset(dp,-1,sizeof(dp));
    return ans(n,0,0);
    }
};