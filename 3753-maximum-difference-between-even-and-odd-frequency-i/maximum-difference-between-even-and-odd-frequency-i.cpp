class Solution {
public:
    int maxDifference(string s) {
        int n = s.size();
        vector<int> freq(26, 0);
        for (char ch : s) {
            freq[ch - 'a']++;
        }
        int emax = 0, emin = INT_MAX;
        for (int i = 0; i < 26; i++) {
            if (freq[i] % 2 == 0 && freq[i] > 0) {
                if (freq[i] < emin)
                    emin = freq[i];
            }
            if (freq[i] % 2 == 1 && freq[i] > 0) {
                if (freq[i] > emax)
                    emax = freq[i];
            }
        }

        return emax - emin;
    }
};