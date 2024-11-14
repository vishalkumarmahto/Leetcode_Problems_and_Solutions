class Solution {
public:
    int findMax(vector<int>& v) {
        int maxi = INT_MIN;
        int n = v.size();
        // find the maximum:
        for (int i = 0; i < n; i++) {
            maxi = max(maxi, v[i]);
        }
        return maxi;
    }

    int calculateTotalHours(vector<int>& v, int hourly) {
        int totalH = 0;
        int n = v.size();
        // find total hours:
        for (int i = 0; i < n; i++) {
            totalH += ceil((double)(v[i]) / (double)(hourly));
        }
        return totalH;
    }
    int minimizedMaximum(int h, vector<int>& v) {
        int low = 1, high = findMax(v);

        // apply binary search:
        while (low <= high) {
            int mid = (low + high) / 2;
            int totalH = calculateTotalHours(v, mid);
            if (totalH <= h) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};