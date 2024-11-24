class Solution {
public:
    int findNumberOfLIS(vector<int>& arr) {
        int n = arr.size();
        vector<int>dp(n,1);
        vector<int>cut(n,1);
        int maxi = 1;
        for(int i=0;i<n;i++){
            for(int prev_index=0;prev_index<i;prev_index++){
                if(arr[prev_index]<arr[i]&& 1 + dp[prev_index]>dp[i]){
                    dp[i] = 1 + dp[prev_index];
                    // inherit

                    cut[i]= cut[prev_index];
                }
                else if(arr[prev_index]<arr[i]&& 1 + dp[prev_index]==dp[i]){
                    cut[i]=cut[i] + cut[prev_index];
                }
            }
            maxi = max(maxi,dp[i]);
        }
        int nos = 0;
        for(int i=0;i<n;i++){
            if(dp[i]==maxi) nos+=cut[i];
        }
        return nos;
    }
};