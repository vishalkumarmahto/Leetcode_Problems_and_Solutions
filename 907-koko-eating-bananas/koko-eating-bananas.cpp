class Solution {
public:
    long long isValid(vector<int>& piles, int& hourly) {
        long long totalHours = 0;
        for (int i = 0; i < piles.size(); i++) {
             totalHours += (piles[i] + hourly - 1) / hourly;
        }
        return totalHours;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxEl = *max_element(piles.begin(), piles.end());
        int low = 1, high = maxEl;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isValid(piles, mid) <= h) {
                high = mid - 1;
            } else
                low = mid + 1;
        }
        return low;
    }
};