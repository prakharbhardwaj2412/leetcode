class Solution {
public:
    int f(int row, int col, vector<vector<int>> &dp)
    {
        if(row==0 && col==0) return dp[row][col]=1;
        if(row<0 || col<0) return 0;
        if(dp[row][col]!=-1) return dp[row][col];
        return dp[row][col]=f(row-1, col, dp)+f(row, col-1, dp);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        f(m-1, n-1, dp);
        return dp[m-1][n-1];
    }
};