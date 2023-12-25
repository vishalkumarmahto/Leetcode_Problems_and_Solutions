class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> sumFreq;
        sumFreq[0]++;
        int sum=0,ans=0;
        for (auto num:nums){
            sum+=num;
            if (sumFreq.find(sum-k)!=sumFreq.end()) ans+=sumFreq[sum-k];
            sumFreq[sum]++;
        }
        return ans;
    }
};