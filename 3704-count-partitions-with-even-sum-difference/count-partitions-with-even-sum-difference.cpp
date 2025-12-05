class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size();
        int totSum = 0;
        for(int i=0;i<n;i++){
            totSum+=nums[i];
        }
        return totSum%2==0?n-1:0;
    }
};