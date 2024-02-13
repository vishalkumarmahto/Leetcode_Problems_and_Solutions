class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for (auto it : words) {
            string s = it;
            reverse(s.begin(), s.end());
            if (s == it) {
                return s;
            }
        }
        return "";
    }
};