class Solution {
public:
    typedef pair<int, int> pi;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        for (auto x : nums) {
            mpp[x]++;
        }
        priority_queue<pi, vector<pi>, greater<pi>> pq;
        for (auto x : mpp) {
            pq.push(make_pair(x.second, x.first));
            if (pq.size() > k) {
                pq.pop();
            }
        }
        vector<int> ans;
        while (!pq.empty()) {
            pi temp = pq.top();
            pq.pop();
            ans.push_back(temp.second);
        }
        return ans;
    }
};