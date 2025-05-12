class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {

        unordered_set<int> st;
        int n = digits.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    if (i == j || j == k || k == i)
                        continue;
                    int num = digits[i] * 100 + digits[j] * 10 + digits[k] * 1;
                    if (num >= 100 && num % 2 == 0)
                        st.insert(num);
                }
            }
        }
        vector<int> ans(st.begin(), st.end());
        sort(ans.begin(), ans.end());
        return ans;
    }
};