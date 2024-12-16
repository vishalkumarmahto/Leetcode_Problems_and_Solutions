class Solution {
public:
    bool isBloomDay(vector<int>& bloomDay, int day, int m, int k) {
        int n = bloomDay.size();
        int cnt = 0, noOfBo = 0;
        for (int i = 0; i < n; i++) {
            if (bloomDay[i] <= day)
                cnt++;
            else {
                noOfBo += (cnt / k);
                cnt = 0;
            }
        }
        noOfBo += (cnt / k);
        if (noOfBo >= m)
            return true;
        else
            return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        long n = bloomDay.size();
        long long val = m* 1ll * k*1ll;
        int maxel = *max_element(bloomDay.begin(), bloomDay.end());
        int minel = *min_element(bloomDay.begin(), bloomDay.end());
        int low = minel, high = maxel;
        if (n < val)
            return -1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (isBloomDay(bloomDay, mid, m, k))
                high = mid - 1;
            else
                low = mid + 1;
        }
        return low;
    }
};