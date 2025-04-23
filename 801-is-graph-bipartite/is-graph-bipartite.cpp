class Solution {
public:
    bool bfs(int start, int color, int col[], vector<vector<int>>& graph) {
        queue<int> q;
        q.push(start);
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (auto it : graph[node]) {
                if (col[it] == -1) {
                    col[it] = !col[node];
                    q.push(it);
                }

                else if (col[it] == col[node])
                    return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        int col[n];
        for (int i = 0; i < n; i++)
            col[i] = -1;
        for (int i = 0; i < n; i++) {
            if (col[i] == -1) {
                if (bfs(i, 0, col, graph) == false)
                    return false;
            }
        }
        return true;
    }
};