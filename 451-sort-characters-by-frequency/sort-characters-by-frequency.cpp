class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mpp;
        vector<pair<int, char>> v;
        string ans = "";

        // count the character frequency
        for (auto ch : s) {
            mpp[ch]++;
        }
        // push from map to vector

        for (auto i : mpp) {
            v.push_back({i.second, i.first});
        }
        // sort the vector in decreasing order
        sort(v.begin(), v.end(), greater<pair<int, char>>());

        // add to final string
        for (auto i : v) {
            while (i.first--)
                ans += i.second;
        }
        return ans;
    }
};