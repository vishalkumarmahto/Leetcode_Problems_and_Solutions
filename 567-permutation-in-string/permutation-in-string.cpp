class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // Store all character frequencies of s1
        unordered_map<char, int> um;
        for (auto& val : s1) {
            um[val]++;
        }

        int m = s1.size();
        int n = s2.size();

        // Loop through all substrings of s2 with the same length as s1
        for (int i = 0; i <= n - m; i++) {
            // Only consider substrings of length equal to s1
            string cur = s2.substr(i, m);
            bool possible = true;

            // Create a temporary copy of the frequency map of s1
            unordered_map<char, int> tmp_um = um;

            for (auto& val : cur) {
                if (tmp_um.find(val) != tmp_um.end()) {
                    if (tmp_um[val] == 0) {
                        possible = false;
                        break;
                    }
                    tmp_um[val]--;
                } else {
                    possible = false;
                    break;
                }
            }

            if (possible)
                return true;
        }

        return false;
    }
};