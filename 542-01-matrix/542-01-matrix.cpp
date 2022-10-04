class Solution {
private:
    void bfs(vector<vector<int>> mat, vector<vector<int>> &vis, vector<vector<int>> &ans)
    {
        int n=mat.size();
        int m=mat[0].size();
        queue<pair<int, int>> q;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(mat[i][j]==0) {
                    vis[i][j]=1;
                    ans[i][j]=0;
                    q.push({i, j});
                }
            }
        }
        int delrow[]={-1, 0, 1, 0};
        int delcol[]={0, 1, 0, -1};
        while(!q.empty()) {
            int row=q.front().first;
            int col=q.front().second;
            // int d=q.front().second;
            q.pop();
            for(int i=0; i<4; i++)
            {
                int nrow=row+delrow[i];
                int ncol=col+delcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && mat[nrow][ncol]==1) {
                    if(ans[nrow][ncol]>ans[row][col]+1) {
                        vis[nrow][ncol]=1;
                        ans[nrow][ncol]=ans[row][col]+1;
                        q.push({nrow, ncol});
                    }
                }
            }
        }
    }
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<vector<int>> ans(n, vector<int>(m, INT_MAX));
        bfs(mat, vis, ans);
        return ans;
    }
};