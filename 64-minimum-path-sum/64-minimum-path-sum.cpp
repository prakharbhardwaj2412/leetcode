// ============================RECURSION
// class Solution {
// public:
//     int f(int i, int j, vector<vector<int>> &grid)
//     {
//         if(i==0 && j==0) return grid[0][0];
//         if(i<0 || j<0) return INT_MAX;
//         int up=f(i-1, j, grid);
//         int left=f(i, j-1, grid);;
//         return grid[i][j]+min(left, up);
        
//     }
//     int minPathSum(vector<vector<int>>& grid) {
//         int n=grid.size();
//         int m=grid[0].size();
//         return f(n-1, m-1, grid);
//     }
// };

// ===========================MEMOIZATION
// class Solution {
// public:
//     int f(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp)
//     {
//         if(i==0 && j==0) return dp[i][j]=grid[0][0];
//         if(i<0 || j<0) return INT_MAX;
//         if(dp[i][j]!=-1) return dp[i][j];
//         int up=f(i-1, j, grid, dp);
//         int left=f(i, j-1, grid, dp);
//         return dp[i][j]=grid[i][j]+min(left, up);
        
//     }
//     int minPathSum(vector<vector<int>>& grid) {
//         int n=grid.size();
//         int m=grid[0].size();
//         vector<vector<int>> dp(n, vector<int>(m, -1));
//         f(n-1, m-1, grid, dp);
//         return dp[n-1][m-1];
//     }
// };

// // ==========================TABULATION
// class Solution {
// public:
//     int minPathSum(vector<vector<int>>& grid) {
//         int n=grid.size();
//         int m=grid[0].size();
//         vector<vector<int>> dp(n, vector<int>(m, 0));
//         for(int i=0; i<n; i++) {
//             for(int j=0; j<m; j++) {
//                 if(i==0 && j==0) dp[i][j]=grid[i][j];
//                 else {
//                     int left=INT_MAX, up=INT_MAX;
//                     if(i>0) left=dp[i-1][j];
//                     if(j>0) up=dp[i][j-1];
//                     dp[i][j]=grid[i][j]+min(left, up);
//                 }
//             }
//         }
//         return dp[n-1][m-1];
//     }
// };

// =========================SPACE OPTIMIZATION
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<int> prev(m);
        for(int i=0; i<n; i++) {
            vector<int> temp(m);
            for(int j=0; j<m; j++) {
                if(i==0 && j==0) temp[j]=grid[i][j];
                else {
                    int left=INT_MAX, up=INT_MAX;
                    if(i>0) up=prev[j];
                    if(j>0) left=temp[j-1];
                    temp[j]=grid[i][j]+min(left, up);
                }
            }
            prev=temp;
        }
        return prev[m-1];
    }
};