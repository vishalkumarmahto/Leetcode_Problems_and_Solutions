class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>mpp;
        for(int i:nums){
             mpp[i]++;
        }
        for(auto it:mpp){
            if(it.second==1)  return it.first;
        }
        return -1;
    }
};