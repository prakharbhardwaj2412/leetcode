class Solution {
public:
    bool dfs(int ind, int dest, vector<int> &vis, vector<int> adj[]) {
        vis[ind] = 1;
        for(auto it : adj[ind]) {
            if(it == dest) return true;
            else if(!vis[it]) {
                if(dfs(it, dest, vis, adj) == true) return true; 
            }
            
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> adj[n];
        if(n==1) return true;
        for(int i=0; i<edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int> vis(n, 0);
        
        return dfs(source, destination, vis, adj);
        
    }
};