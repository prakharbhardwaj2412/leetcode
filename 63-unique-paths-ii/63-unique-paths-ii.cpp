class Solution {
public:
    int f(int row, int col, vector<vector<int>> &dp, vector<vector<int>> obsGrid)
    {
        if(row==0 && col==0 ) 
        {
            if(obsGrid[row][col]==1) return dp[row][col]=0;
            else return dp[row][col]=1;
        }
        if(row<0 || col<0) return 0;
        if(obsGrid[row][col]==1) dp[row][col]=0;
        if(dp[row][col]!=-1) return dp[row][col];
        return dp[row][col]=f(row-1, col, dp, obsGrid)+f(row, col-1, dp, obsGrid);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        f(m-1, n-1, dp, obstacleGrid);
        return dp[m-1][n-1];
        
    }
};