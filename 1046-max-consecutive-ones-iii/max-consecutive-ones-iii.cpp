class Solution {
public:
    int longestOnes(vector<int>& arr, int k) {
        
        int n = arr.size();
        int left = 0, right = 0, maxLen = 0;
        int zeros = 0;
        while(right<n){
            if(arr[right]==0) zeros++;
            if(zeros>k){
                if(arr[left]==0) zeros--;
                left++;
            }
            if(zeros<=k){
                int len = right - left + 1;
                maxLen = max(maxLen,len);
            }
            right++;
        }
        return maxLen;
    }
};