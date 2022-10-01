class Solution {
private:
    void dfs(int row, int col, vector<vector<int>>& image, vector<vector<bool>> &vis, int newColor, int prevColor)
    {
        vis[row][col]=true;
        image[row][col]=newColor;
        int n=image.size();
        int m=image[0].size();
        for(int delrow=-1; delrow<=1; delrow++)
        {
            for(int delcol=-1; delcol<=1; delcol++)
            {
                if(delrow+delcol==-2 || delrow+delcol==0 || delrow+delcol==2) continue;
                int nrow=row+delrow;
                int ncol=col+delcol;
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && image[nrow][ncol]==prevColor)
                {
                    dfs(nrow, ncol, image, vis, newColor, prevColor);
                }
            }
        }
        
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        dfs(sr, sc, image, vis, color, image[sr][sc]);
        return image;
    }
};