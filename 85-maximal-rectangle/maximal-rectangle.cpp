class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        int n = arr.size();
        int maxArea = 0;
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                int el = st.top();
                st.pop();
                int pse = st.empty() ? -1 : st.top();
                maxArea = max(maxArea, (i - pse - 1) * arr[el]);
            }
            st.push(i);
        }
        while (!st.empty()) {
            int el = st.top();
            st.pop();
            int pse = st.empty() ? -1 : st.top();
            maxArea = max(maxArea, (n - pse - 1) * arr[el]);
        }
        return maxArea;
    }
    int maximalRectangle(vector<vector<char>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int maxArea = 0;
        vector<vector<int>> preSum(n, vector<int>(m, 0));
        for (int j = 0; j < m; j++) {
            int sum = 0;
            for (int i = 0; i < n; i++) {
              
                if (mat[i][j] == '1') {
                    sum++;
                } else {
                    sum = 0;
                }
                preSum[i][j] = sum;
            }
        }
        for (int i = 0; i < n; i++) {
            maxArea = max(maxArea, largestRectangleArea(preSum[i]));
        }
        return maxArea;
    }
};