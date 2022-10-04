class Solution {
private:
    void bfs(int row, int col, vector<vector<int>> &temp)
    {
      temp[row][col]=0;
      int n=temp.size();
        int m=temp[0].size();
      queue<pair<int, int>> q;
      q.push({row, col});
      int delrow[]={-1, 0, 1, 0};
      int delcol[]={0, 1, 0, -1};
      while(!q.empty())
      {
          int row=q.front().first;
          int col=q.front().second;
          q.pop();
          for(int i=0; i<4; i++)
          {
              int nrow=row+delrow[i];
              int ncol=col+delcol[i];
              if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && temp[nrow][ncol]==1)
              {
                  temp[nrow][ncol]=0;
                  q.push({nrow, ncol});
              }
          }

      }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
       vector<vector<int>> temp=grid;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0; i<n; i++)
        {
            if(grid[i][0]==1) bfs(i, 0, temp);
            if(grid[i][m-1]==1) bfs(i, m-1, temp);
        }
        for(int j=0; j<m; j++)
        {
            if(grid[0][j]==1) bfs(0, j, temp);
            if(grid[n-1][j]==1) bfs(n-1, j, temp);
        }
        int count=0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(temp[i][j]==1) count++;
            }
        }
        return count; 
    }
};