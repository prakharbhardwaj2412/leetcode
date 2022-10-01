class Solution {
private:
    void dfs(int node, vector<int> &vis, vector<int> adj[])
    {
        vis[node]=1;
        for(auto it:adj[node])
            if(!vis[it])
                dfs(it, vis, adj);
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V=isConnected.size();
        vector<int> adj[V];
//         to change adjacency matrix to list
        for(int i=0; i<V; i++)
        {
            for(int j=0; j<V; j++)
            {
                if(isConnected[i][j]==1 && i!=j)
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int count=0;
        // int vis[V];
        vector<int> vis(V, 0);
        // for(int i=0; i<V; i++) vis[i]=0;
        for(int i=0; i<V; i++)
        {
            cout<<i<<" "<<vis[i]<<" "<<count<<endl;
            if(!vis[i])
            {
                dfs(i, vis, adj);
                count++;
            }
        }
        return count;
    }
};