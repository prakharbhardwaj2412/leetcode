class Solution {
private:
    void dfs(int row, int col, vector<vector<int>>& image, vector<vector<int>> &ans, int newColor, int prevColor)
    {
        ans[row][col]=newColor;
        int n=image.size();
        int m=image[0].size();
        int delrow[]={-1, 0, +1, 0};
        int delcol[]={0, +1, 0, -1};
        for(int i=0; i<4; i++)
        {
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && ans[nrow][ncol]!=newColor && image[nrow][ncol]==prevColor)
                dfs(nrow, ncol, image, ans, newColor, prevColor);
        }
        
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> ans=image;
        dfs(sr, sc, image, ans, color, image[sr][sc]);
        return ans;
    }
};