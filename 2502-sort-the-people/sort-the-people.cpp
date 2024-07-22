class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        unordered_map<int, string> map;
        for (int i = 0; i < names.size(); i++)
            map[heights[i]] = names[i];
        sort(heights.begin(), heights.end(), greater<int>());
        for (int i = 0; i < names.size(); i++)
            names[i] = map[heights[i]];
        return names;
    }
};