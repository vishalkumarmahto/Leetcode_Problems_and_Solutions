class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        unordered_map<char,int> mpp;
        int left = 0;
        int right = 0;
        int maxLen = 0;
        while(right<n){
            if(mpp.find(s[right])!=mpp.end()){
                if(mpp[s[right]]>=left){
                    left = mpp[s[right]]+1;
                }
            }
            int len = right-left+1;
            maxLen = max(len,maxLen);
            mpp[s[right]]=right;
            right++;
        }
        return maxLen;
    }
};