class Solution {
public:
    int dfs(int ind, int n, vector<int> &vis, vector<vector<int>> &stones) {
        vis[ind]=1;
        int result=0;
        for(int i=0; i<n; i++) {
            if(!vis[i] && (stones[ind][0]==stones[i][0] || stones[ind][1]==stones[i][1])) {
                result+=dfs(i, n, vis, stones)+1;
            }
        }
        return result;
    }
    int removeStones(vector<vector<int>>& stones) {
        int result=0, n=stones.size();
        vector<int> vis(n, 0);
        for(int i=0; i<n; i++) {
            if(!vis[i]) result+=dfs(i, n, vis, stones);
        }
        
        return result;
    }
};