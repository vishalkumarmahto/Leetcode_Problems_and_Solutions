class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        int n = arr.size();
        int maxArea = 0;
        stack<int>st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                int el = st.top();
                st.pop();
                int pse = st.empty() ? -1 : st.top();
                maxArea = max(maxArea, (i - pse - 1) * arr[el]);
            }
            st.push(i);
        }
        while(!st.empty()){
            int el = st.top();
            st.pop();
            int pse = st.empty() ? -1 : st.top();
            maxArea = max(maxArea,(n-pse-1)*arr[el]);
        }
        return maxArea;
    }
};