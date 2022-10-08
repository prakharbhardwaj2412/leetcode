class Solution {
private:
    bool detectCycleDFS(int node, vector<int> &vis, vector<int> &pathVis, vector<int> &check, vector<vector<int>> &graph) {
        vis[node]=1;
        pathVis[node]=1;
        for(int adjNode : graph[node]) {
            if(!vis[adjNode]) {
                if(detectCycleDFS(adjNode, vis, pathVis, check, graph) == true) 
                {
                    check[node]=0;
                    return true;
                }
            } else if(pathVis[adjNode]) return true;
        }
        pathVis[node]=0;
        check[node]=1;
        return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V=graph.size();
        vector<int> vis(V, 0);
        vector<int> pathVis(V, 0);
        vector<int> check(V, 0);
        for(int i=0; i<V; i++) {
            if(!vis[i]) 
                detectCycleDFS(i, vis, pathVis, check, graph);
        }
        vector<int> ans;
        for(int i=0; i<V; i++) {
            if(check[i]==1) ans.push_back(i);
        }
        return ans;
        
    }
};