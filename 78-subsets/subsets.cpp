class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        int n = nums.size();
        int subsets = 1<<n;
        for(int k = 0;k<subsets;k++){
            vector<int>ans1;
            for(int i=0;i<n;i++){
                if(k&(1<<i)) ans1.push_back(nums[i]);
            }
            ans.push_back(ans1);
        }
        return ans;
    }
};