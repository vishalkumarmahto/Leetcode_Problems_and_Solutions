class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int lastOccur[256]; // Array to store last occurrence index of characters
        memset(lastOccur, -1, sizeof(lastOccur)); // Initialize array with -1
        
        int left = 0, maxLen = 0;
        
        for (int right = 0; right < n; right++) {
            char ch = s[right];
            if (lastOccur[ch] != -1 && lastOccur[ch] >= left) {
                left = lastOccur[ch] + 1;
            }
            int len = right - left + 1;
            maxLen = max(len, maxLen);
            lastOccur[ch] = right;
        }
        
        return maxLen;
    }
};