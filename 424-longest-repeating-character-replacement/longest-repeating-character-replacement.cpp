class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0, right = 0, maxFreq = 0;
        int maxLen = 0;
        int hash[26] = {0};
        while (right < s.length()) {
            hash[s[right] - 'A']++;
            maxFreq = max(maxFreq, hash[s[right] - 'A']);
            if ((right - left + 1) - maxFreq > k) {
                hash[s[left] - 'A']--;
                left++;
            }
            if ((right - left + 1) - maxFreq <= k) {
                maxLen = max(maxLen, right - left + 1);
            }
            right++;
        }
        return maxLen;
    }
};