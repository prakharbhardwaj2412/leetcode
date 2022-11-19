class Solution {
public:
    void dfs(int ind, vector<int> &vis, vector<int> &visCount, vector<int> adj[]) {
        vis[ind] = 1;
        for(auto it : adj[ind]) {
            if(!vis[it]) dfs(it, vis, visCount, adj);
            visCount[it]++;
        }
    }
    int findCenter(vector<vector<int>>& edges) {
        int V = 0;
        for(int i = 0; i < edges.size(); i++) {
            V = max(V, max(edges[i][0], edges[i][1]));
        }
        vector<int> adj[V+1];
        for(int i=0; i<edges.size(); i++) {
            int u = edges[i][0], v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> vis(V+1, 0);
        vector<int> visCount(V+1, 0);
        
        for(int i=1; i<V+1; i++) {
            if(!vis[i]) dfs(i, vis, visCount, adj);
        }
        int center = 0;
        for(int i = 1; i < V + 1; i++) if(visCount[i] > 1) center = i;
        return center;;
    }
};