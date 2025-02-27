class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        if (arr.size() < 2)
            return 0;
        int n = arr.size();
        unordered_map<int, int> mpp;
        for (int i = 0; i < n; i++) {
            mpp[arr[i]] = i;
        }
        int maxi = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int prev = arr[j];
                int prevv = arr[i];
                int len = 2;
                while (mpp.find(prev + prevv) != mpp.end()) {
                    len++;
                    maxi = max(maxi, len);
                    int x = prev;
                    prev = prev + prevv;
                    prevv = x;
                }
            }
        }
        return maxi > 2 ? maxi : 0;
    }
};