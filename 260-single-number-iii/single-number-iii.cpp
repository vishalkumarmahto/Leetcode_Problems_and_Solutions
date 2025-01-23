class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans;
        unordered_map<int,int>mpp;
        for(int i: nums){
             mpp[i]++;
        }
        for(auto it:mpp){
            if(it.second==1) ans.push_back(it.first);
        }
        return ans;
    }
};