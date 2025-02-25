class Solution {
public:
    long long numOfSubarrays(vector<int>& arr) {
        const int MOD=1e9+7;
        long long oddCount = 0, evenCount = 1;
        long long prefixSum = 0, result = 0;
        for (int nums : arr) {
            prefixSum += nums;
            if (prefixSum % 2 == 1) {
                result += evenCount;
                oddCount++;
            } else {
                result += oddCount;
                evenCount++;
            }
        }
        return result%MOD;
    }
};