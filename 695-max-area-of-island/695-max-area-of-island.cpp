class Solution {
private:
//     bredth first search approach========================
    void bfs(int row, int col, vector<vector<bool>> &vis, vector<vector<int>>& grid, int &ans)
    {
        vis[row][col]=true;
        queue<pair<int, int>> q;
        q.push({row, col});
        int n=grid.size();
        int m=grid[0].size();
        int area=1;
        while(!q.empty())
        {
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            
            for(int delrow=-1; delrow<=1; delrow++)
            {
                for(int delcol=-1; delcol<=1; delcol++)
                {
                    if(delcol+delrow==-2 || delcol+delrow==0 || delcol+delrow==2) continue;
                    int nrow=row+delrow;
                    int ncol=col+delcol;
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && 
                    grid[nrow][ncol]==1)
                    {
                        q.push({nrow, ncol});
                        vis[nrow][ncol]=true;
                        area++;
                    }
                }
            }
        }
        ans=max(area, ans);
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans=0;
        int n=grid.size(), m=grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        // int count=0;
        for(int row=0; row<n; row++)
        {
            for(int col=0; col<m; col++)
            {
                if(!vis[row][col] && grid[row][col]==1)
                {
                    // count++;
                    bfs(row, col, vis, grid, ans);
                }
            }
        }
        return ans;
    }
};