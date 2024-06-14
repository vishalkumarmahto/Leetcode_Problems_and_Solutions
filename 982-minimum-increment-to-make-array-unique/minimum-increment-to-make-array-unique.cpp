class Solution {
public:
    int minIncrementForUnique(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int moves = 0;
        for (int i = 1; i < n; i++) {
            if (arr[i] <= arr[i - 1]) {
                moves += (arr[i - 1] - arr[i] + 1);
                arr[i] = arr[i - 1] + 1;
            }
        }
        return moves;
    }
};