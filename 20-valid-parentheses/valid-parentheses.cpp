class Solution {
public:
    bool isValid(string s) {
        stack<char> mp;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                mp.push(s[i]);
            } else {
                if (mp.empty()) {
                    return false;
                }
                if ((s[i] == ')' && mp.top() == '(') ||
                    (s[i] == ']' && mp.top() == '[') ||
                    (s[i] == '}' && mp.top() == '{')) {
                    mp.pop();
                } else {
                    return false;
                }
            }
        }
        return mp.empty();
    }
};