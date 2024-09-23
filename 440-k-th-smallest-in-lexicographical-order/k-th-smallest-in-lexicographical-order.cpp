class Solution {
public:
    long countSteps(long curr, long n) {
        long steps = 0, first = curr, last = curr;
        while (first <= n) {
            steps += min(n + 1, last + 1) - first;
            first *= 10;
            last = last * 10 + 9;
        }
        return steps;
    }

    int findKthNumber(int n, int k) {
        long curr = 1; // Start from the first prefix (1)
        k--;           // Decrease k by 1 because we are starting from 1

        while (k > 0) {
            long steps = countSteps(curr, n);
            if (steps <= k) {
                curr++; // Move to the next sibling (prefix)
                k -= steps;
            } else {
                curr *= 10; // Move to the first child
                k--;        // We have covered the current number
            }
        }

        return curr;
    }
};