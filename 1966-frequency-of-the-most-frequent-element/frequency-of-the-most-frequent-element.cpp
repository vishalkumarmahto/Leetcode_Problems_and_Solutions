class Solution {
public:
    int maxFrequency(vector<int> &nums, int k) {
    
        int res = 0, len = nums.size();
        long tot = 0, curr;
        sort(begin(nums), end(nums));
        for (int i = 0, j = 0, currLen = 0; j < len; j++) {
           
            curr = nums[j];
            currLen++;
            tot += curr;
           
            while (curr * currLen - tot > k) {
                tot -= nums[i++];
                currLen--;
            }
            
            res = max(res, currLen);
        }
        return res;
    }
};