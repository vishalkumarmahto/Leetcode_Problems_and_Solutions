class Solution {
public:
    string longestCommonPrefix(vector<string>& arr) {
        string s1 = arr[0];
        int ans = s1.length();

        for (int i = 1; i < arr.size(); i++) {
            int j = 0;
            while (j < s1.size() && j < arr[i].size() && s1[j] == arr[i][j]) {
                j++;
            }
            ans = min(ans, j);
        }
        string res = s1.substr(0, ans);
       
        return res;
    }
};