class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        int i = 0, j = 0;
        vector<int> ans;
        int n1 = a.size(), n2 = b.size();
        while (i < n1 && j < n2) {
            if (a[i] < b[j]) {
                ans.push_back(a[i++]);
            } else
                ans.push_back(b[j++]);
        }
        while (i < n1)
            ans.push_back(a[i++]);
        while (j < n2)
            ans.push_back(b[j++]);
        int n = n1 + n2;
        if (n % 2 == 1)
            return ans[n / 2];
        else
            return ((double)ans[n / 2] + (double)ans[n / 2 - 1]) / 2;
    }
};