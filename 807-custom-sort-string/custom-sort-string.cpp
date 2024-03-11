class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char, int> charCount;
        for (auto c : order) {
            charCount[c] = 0;
        }
        for (auto c : s) {
            if (charCount.find(c) != charCount.end()) {
                charCount[c]++;
            }
        }
        string sortedS;
        for (auto c : order) {
            sortedS.append(charCount[c], c);
        }
        for (auto c : s) {
            if (charCount.find(c) == charCount.end()) {
                sortedS.push_back(c);
            }
        }
        return sortedS;
    }
};