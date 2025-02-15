class Solution {
public:
    bool check(int square, int curSum, int target) {
        if (square == 0)
            return target == curSum;
        return check(square / 10, square % 10 + curSum, target) ||
               check(square / 100, square % 100 + curSum, target) ||
               check(square / 1000, square % 1000 + curSum, target) ||
               check(square / 10000, square % 10000 + curSum, target);
    }
    int punishmentNumber(int n) {
        int res = 0;
        for (int i = 1; i <= n; i++) {
            int sq = i * i;
            if (check(sq, 0, i) == true) {
                res += sq;
            }
        }
        return res;
    }
};