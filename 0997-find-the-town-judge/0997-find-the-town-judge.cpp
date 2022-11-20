class Solution {
public:
//     void dfs(int ind, vector<int> &vis, vector<int> &pathVis, vector<int> adj[]) {
//         vis[ind] = 1;
//         pathVis[ind] = 1;
        
//         pathVis[ind] = 0;
//     }
    int findJudge(int n, vector<vector<int>>& trust) {
        set<int> adj[n + 1];
        for(int i = 0; i < trust.size(); i++) {
            adj[trust[i][0]].insert(trust[i][1]);
        } 
        
        for(int i = 1; i< n + 1; i++) {
            adj[i].insert(0);
        }
        
//         vector<int> vis(n, 0);
//         vector<int> pathVis(n, 0);
        
//         for(int i = 0; i < n; i++) {
//             if(!vis[i]) dfs(i, vis, pathVis, adj);
//         }
        int judge = -1;
        for(int i = 0; i < n + 1; i++) {
            if(adj[i].size() == 1 &&  adj[i].find(0) != adj[i].end()) {
                judge =  i;
                break;
            }
        }
        cout<<judge<<endl;
        for(int i = 1; i< n + 1; i++) if(i!=judge && adj[i].find(judge) == adj[i].end()) return -1;
        
        return judge;
    }
};