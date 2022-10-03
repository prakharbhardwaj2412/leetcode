class Solution {
public:
    int bfs(vector<vector<int>> grid, vector<vector<int>> &ans, vector<vector<int>> &vis)
    {
        int n=grid.size();
        int m=grid[0].size();
//         {{row, col}, min}
        queue<pair<pair<int, int>, int>> q;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j]==2) q.push({{i, j}, 0});
            }
        }
        int time=0;
        int delrow[]={-1, 0, +1, 0};
        int delcol[]={0, 1, 0, -1};
        while(!q.empty())
        {
            int row=q.front().first.first;
            int col=q.front().first.second;
            time=max(time, q.front().second);
            q.pop();
            for(int i=0; i<4; i++)
            {
                int nrow=row+delrow[i];
                int ncol=col+delcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && ans[nrow][ncol]==1)
                {
                    ans[nrow][ncol]=2;
                    q.push({{nrow, ncol}, time+1});
                }
            }
        }
        return time;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<vector<int>> ans=grid;
        int time=bfs(grid, ans, vis);
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(ans[i][j]==1) return -1;
            }
        }
        return time;
    }
};