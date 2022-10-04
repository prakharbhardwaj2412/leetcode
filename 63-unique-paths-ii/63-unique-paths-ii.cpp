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
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                
                if(i==0 && j==0) dp[i][j]=1;
                else 
                {
                    int left=0, up=0;
                    if(i>0) up=dp[i-1][j];
                    if(j>0) left=dp[i][j-1];
                    dp[i][j]=left+up;
                }
                if(obstacleGrid[i][j]==1) dp[i][j]=0;
            }
        }
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n;j++)
                cout<<dp[i][j]<<" ";
            cout<<endl;
        }
        // f(m-1, n-1, dp, obstacleGrid);
        return dp[m-1][n-1];
        
    }
};