class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int n = nums.size();
        int maxElement = *max_element(nums.begin(), nums.end());
        vector<int> count(n + maxElement, 0);
        for (int& num : nums) {
            count[num]++;
        }
        int moves = 0;
        for (int i = 0; i < n + maxElement; i++) {
            if (count[i] <= 1) {
                continue;
            }
            int extra = count[i] - 1;
            count[i + 1] += extra;
            count[i] = 1;
            moves += extra;
        }
        return moves;
    }
};