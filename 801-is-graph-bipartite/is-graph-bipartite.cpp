class Solution {

    private:
     bool isBipartite(int start, int V, vector<vector<int>>& graph, int col[]){
        queue<int>q;
        q.push(start);
        col[start] = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto it:graph[node]){
                if(col[it]==-1){
                    col[it] = !col[node];
                    q.push(it);
                }
                else if(col[it]==col[node]) return false;
            }
        }
        return true;

     }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        int col[V];
        for(int i=0;i<V;i++) col[i] = -1;
        for(int i=0;i<V;i++){
            if(col[i]==-1)
            if(isBipartite(i,V,graph,col)==false) return false;
        }
        return true;
    }
};