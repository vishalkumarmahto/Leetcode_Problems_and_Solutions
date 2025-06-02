class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int sum = 1, i = 1;
        while (i < n) {
            if (ratings[i] == ratings[i - 1]) {
                sum = sum + 1;
                i++;
                continue;
            }
            int peak = 1;
            while (i < n && ratings[i] > ratings[i - 1]) {
                peak += 1;
                sum += peak;
                i++;
            }
            int down = 1;
            while (i < n && ratings[i] < ratings[i - 1]) {
                i++;
                sum += down;
                down += 1;
            }
            if (down > peak) {
                sum += down - peak;
            }
           
        }
        return sum;
    }
};