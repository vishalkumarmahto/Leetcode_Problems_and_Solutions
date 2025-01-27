class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty()) {
            return "";
        }

        vector<int> freq(256);
        for (int i = 0; i < t.size(); i++) {
            freq[t[i]]++;
        }

        int minSize = INT_MAX, count = 0, sIndex = 0, l = 0, r = 0;

        while (r < s.size()) {
            if (freq[s[r]] > 0)
                count++;
            freq[s[r]]--;
            while (count == t.size()) {
                if (r - l + 1 < minSize) {
                    minSize = r - l + 1;
                    sIndex = l;
                }
                freq[s[l]]++;
                if (freq[s[l]] > 0)
                    count--;
                l++;
            }
            r++;
        }

        if (sIndex == 0 && minSize == INT_MAX)
            return "";
        return s.substr(sIndex, minSize);
    }
};