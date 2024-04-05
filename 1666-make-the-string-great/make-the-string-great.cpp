class Solution {
public:
    string makeGood(string s) {
        while (1) {
            stack<char> st;
            st.push(s[0]);
            int ind = 0;
            int a = s.size();
            for (int i = 1; i < s.size(); i++) {
                if (s[i] + 32 == st.top() or s[i] - 32 == st.top()) {
                    s.erase(s.begin() + i);
                    s.erase(s.begin() + ind);
                    st.pop();
                }
                ind = i;
                st.push(s[i]);
            }
            if (a == s.size())
                return s;
        }
        return "";
    }
};