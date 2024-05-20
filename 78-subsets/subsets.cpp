class Solution {
public:
    void solve(vector<int>& nums, int ind, vector<int>& temp,
               vector<vector<int>>& ans) {
        if (ind == nums.size()) {
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[ind]);
        solve(nums, ind + 1, temp, ans);
        temp.pop_back();
        solve(nums, ind + 1, temp, ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> ans;
        solve(nums, 0, temp, ans);
        return ans;
    }

};