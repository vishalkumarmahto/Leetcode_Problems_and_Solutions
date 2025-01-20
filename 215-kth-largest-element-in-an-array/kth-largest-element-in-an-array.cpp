class Solution {
public:
    int findKthLargest(vector<int>& arr, int k) {
        priority_queue<int> pq(arr.begin(), arr.end());
        int ans = 0;
        while (k--) {
            ans = pq.top();
            pq.pop();
        }
        return ans;
    }
};