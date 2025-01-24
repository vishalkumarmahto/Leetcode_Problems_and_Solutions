class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>mpp;
        int n = s.length();
        int start = 0, end = n, maxLen = 0;
        for(int i=0;i<n;i++){
            if(mpp.find(s[i])!=mpp.end()&& mpp[s[i]]>=start){
                start = mpp[s[i]] + 1;
            }
            mpp[s[i]] = i;
            maxLen = max(maxLen,i-start+1);
        }
        return maxLen;
    }
};