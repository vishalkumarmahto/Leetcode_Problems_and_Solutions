class Solution {
public:
    int trap(vector<int>& arr) {
        int left = 0, right = arr.size() - 1;

        int leftmax = 0, rightmax = 0;
        int sum = 0;
        while (left < right) {
            leftmax = max(leftmax, arr[left]);
            rightmax = max(rightmax, arr[right]);
            if (arr[left] < arr[right]) {
                sum += leftmax - arr[left++];

            } else
                sum += rightmax - arr[right--];
        }

        return sum;
    }
};