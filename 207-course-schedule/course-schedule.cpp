class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int V = numCourses;
        vector<vector<int>> adjList(V);
        for (auto it : prerequisites) {
            int course = it[0];
            int prereq = it[1];
            adjList[course].push_back(prereq);
        }
        vector<int>indegree(V,0);
        for(int i=0;i<V;i++){
            for(auto it:adjList[i]){
                indegree[it]++;
            }
        }
        queue<int>q;
        for(int i=0;i<V;i++){
            if(indegree[i]==0) q.push(i);
        }
        vector<int>topo;
        while(!q.empty()){
           int node = q.front();
           q.pop();
           topo.push_back(node);
           for(auto it:adjList[node]){
            indegree[it]--;
            if(indegree[it]==0) q.push(it);
           }

        }
        if(topo.size()==V) return true;
        return false;
    }
};