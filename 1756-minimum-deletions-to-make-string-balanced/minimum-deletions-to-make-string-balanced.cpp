class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.length();
        stack<char> st;
        int count = 0;
        st.push(s[0]);
        for (int i = 1; i < n; i++) {
            if (!st.empty() && (st.top() == 'b' && s[i] == 'a')) {
                st.pop();
                count += 1;
            } else {
                st.push(s[i]);
            }
        }
        return count;
    }
};