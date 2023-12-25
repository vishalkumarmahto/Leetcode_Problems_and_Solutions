class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> sumFreq; 
        int count = 0;
        int sum = 0;

        
        sumFreq[0] = 1;

        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];

           
            if (sumFreq.find(sum - k) != sumFreq.end()) {
                count += sumFreq[sum - k];
            }

           
            sumFreq[sum]++;
        }

        return count;
    }
};