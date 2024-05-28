class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int res = 0;
        int cur_cost = 0;
        int cur_start = 0;

        for (int last_ind = 0; last_ind < s.size(); last_ind++) {
            cur_cost += abs(s[last_ind] - t[last_ind]);

            while (cur_cost > maxCost) {
                cur_cost -= abs(s[cur_start] - t[cur_start]);
                cur_start++;
            }

            if (last_ind - cur_start + 1 > res) {
                res = last_ind - cur_start + 1;
            }
        }

        return res;
    }
};