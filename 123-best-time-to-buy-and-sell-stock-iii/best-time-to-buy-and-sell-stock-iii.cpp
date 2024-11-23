class Solution {
    private:
    int f(int ind, int trans, vector<int>&prices,vector<vector<int>>&dp){
        if(ind==prices.size()||trans==4) return 0;
        int profit = 0;
        if(dp[ind][trans]!=-1) return dp[ind][trans];
        if(trans%2==0) // buy
        {
            profit = max(-prices[ind]+ f(ind+1,trans+1,prices,dp),0+f(ind+1,trans,prices,dp));

        }
        else{
            profit = max(prices[ind]+f(ind+1,trans+1,prices,dp), 0 + f(ind+1,trans,prices,dp));
        }
        return dp[ind][trans] = profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n,vector<int>(4,-1));
        return f(0,0,prices,dp);


    }
};