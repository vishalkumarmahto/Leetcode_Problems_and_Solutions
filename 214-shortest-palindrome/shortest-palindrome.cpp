class Solution {
public:
    string shortestPalindrome(string s) {
        // Create reversed string
        string rev_s = s;
        reverse(rev_s.begin(), rev_s.end());

        // Combine original and reversed strings with a delimiter
        string temp = s + "#" + rev_s;

        // Initialize LPS (Longest Prefix which is also Suffix) array
        vector<int> lps(temp.length(), 0);
        // compute LPS array
        int len = 0, i = 1;
        while (i < temp.length()) {
            if (temp[i] == temp[len]) {
                lps[i] = ++len;
                i++;
            } else if (len > 0) {
                len = lps[len - 1];
            } else {
                i++;
            }
        }
        string add = s.substr(lps.back());
        reverse(add.begin(), add.end());
        return add + s;
    }
};