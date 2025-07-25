class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_set<int> makeUnique;
        for (int i : nums) {
            if (i > 0)
                makeUnique.insert(i);
        }
        if (makeUnique.empty())
            return *max_element(nums.begin(),nums.end());
        return accumulate(makeUnique.begin(), makeUnique.end(),0);
    }
};