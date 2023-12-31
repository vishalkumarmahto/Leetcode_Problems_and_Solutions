class Solution {
public:
    long long isValid(int mid, vector<int>& piles, int h) {
        long long curr = 0;
        for (auto &p:piles) {
            if (p <= mid) curr += 1;
            else {
                curr += p / mid;
                if (p % mid != 0) curr += 1;
            }
        }
        return curr;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = 10000000000;
        int mid;
        int k;
        while (low <= high) {
            mid = (low + high) / 2;
            k = isValid(mid, piles, h);
            if (k <= h) {
                high = mid - 1;
            }
            if (k > h) low = mid + 1;
        }
        return low;
    }
};