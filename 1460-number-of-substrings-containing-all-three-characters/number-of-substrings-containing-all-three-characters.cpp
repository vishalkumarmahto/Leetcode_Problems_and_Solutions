class Solution {
public:
    int numberOfSubstrings(string s) {
        int cnta = 0, cntb = 0, cntc = 0;
        int ans1 = 0, j = 0, i = 0;
        while (j < s.size()) {
            if (s[j] == 'a')
                cnta++;
            else if (s[j] == 'b')
                cntb++;
            else
                cntc++;
            while (cnta && cntb && cntc) { // calc where abc not present at once
                if (s[i] == 'a')
                    cnta--;
                else if (s[i] == 'b')
                    cntb--;
                else
                    cntc--;
                i++;
            }
            ans1 += j - i + 1;
            j++;
        }
        long long n = s.size();
        long long ans = (n * (n + 1)) / 2;
        return ans - ans1;
    }
};