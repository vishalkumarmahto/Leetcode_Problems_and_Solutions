class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int cntNeg = 0, cntPos = 0;
        int ans = 0;
        for(auto it:nums){
            if(it<0) cntNeg++;
            else if(it>0) cntPos++;
        }
        ans = max(cntNeg,cntPos);
        return ans;
        
    }
};