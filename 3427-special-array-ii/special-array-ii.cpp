class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums,
                                vector<vector<int>>& queries) {
        int n = nums.size();
        int prev = nums[0] & 1;
        vector<int> sameParity(n, 0);

        for (int i = 1, j = 0; i < n; i++) {
            bool x = nums[i] & 1;
            if (x == prev)
                j++;
            sameParity[i] = j;
            prev = x;
        }
        int m = queries.size();
        vector<bool> ans(m, 0);
        for (int i = 0; i < m; i++) {
            int s = queries[i][0], t = queries[i][1];
            ans[i] = (sameParity[s] == sameParity[t]);
        }
        return ans;
    }
};