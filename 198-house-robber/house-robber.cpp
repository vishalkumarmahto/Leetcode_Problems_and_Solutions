class Solution {
public:
    int rob(vector<int>& nums) {
        int rob = 0;
        int noRob = 0;
        for(int i=0;i<nums.size();i++){
            int newRob = noRob + nums[i];
            int newNoRob = max(noRob,rob);
            rob=newRob;
            noRob = newNoRob;
        }
        return max(rob,noRob);
    }
};