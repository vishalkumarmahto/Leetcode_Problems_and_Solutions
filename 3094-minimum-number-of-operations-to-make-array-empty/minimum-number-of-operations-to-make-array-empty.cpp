class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n= nums.size();
        int ans = 0;
        unordered_map<int,int> mpp;
       for(int i=0;i<n;i++){
           mpp[nums[i]]++;
       }
       for(auto it : mpp){
           if(it.second==1) return -1;
           ans+=ceil((double)it.second/3);
       }
       return ans;

        
    }
};