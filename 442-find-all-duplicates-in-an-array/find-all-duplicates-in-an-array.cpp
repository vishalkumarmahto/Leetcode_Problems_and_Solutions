class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int,int> mpp;
        for(auto it : nums){
            mpp[it]++;
        }
        for(auto it : mpp){
            if(it.second==2) ans.push_back(it.first);
        }
        return ans;
    }
};