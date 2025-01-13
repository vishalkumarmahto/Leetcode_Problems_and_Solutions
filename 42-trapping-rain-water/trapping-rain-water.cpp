class Solution {
public:
    int trap(vector<int>& arr) {
        int n = arr.size();
        int leftMax = 0, rightMax = 0, total = 0, left = 0, right = n - 1;
        while (left <= right) {
            if (arr[left] <= arr[right]) {
                if (leftMax > arr[left]) {
                    total += leftMax - arr[left];
                } else {
                    leftMax = arr[left];
                }
                left++;
            } else {

                if (rightMax > arr[right]) {
                    total += rightMax - arr[right];
                } else {
                    rightMax = arr[right];
                }
                right--;
            }
        }
        return total;
    }
};