// // // // =========================RECURSION
// // // class Solution {
// // // public:
// // //     int f(int row, int col)
// // //     {
// // //         if(row==0 && col==0) return 1;
// // //         if(row<0 || col<0) return 0;
// // //         return f(row-1, col)+f(row, col-1);
// // //     }
// // //     int uniquePaths(int m, int n) {
// // //         return f(m-1, n-1);
// // //     }
// // // };
// // // =========================MEMOIZATION
// // class Solution {
// // public:
// //     int f(int row, int col, vector<vector<int>> &dp)
// //     {
// //         if(row==0 && col==0) return dp[row][col]=1;
// //         if(row<0 || col<0) return 0;
// //         if(dp[row][col]!=-1) return dp[row][col];
// //         return dp[row][col]=f(row-1, col, dp)+f(row, col-1, dp);
// //     }
// //     int uniquePaths(int m, int n) {
// //         vector<vector<int>> dp(m, vector<int>(n, -1));
// //         f(m-1, n-1, dp);
// //         return dp[m-1][n-1];
// //     }
// // };
// // ===========================TABULATION
// class Solution {
// public:
//     int uniquePaths(int m, int n) {
//         vector<vector<int>> dp(m, vector<int>(n));
//         for(int i=0; i<m; i++)
//         {
//             for(int j=0; j<n; j++)
//             {
//                 if(i==0 && j==0) dp[i][j]=1;
//                 else
//                 {
//                     int left=0, up=0;
//                     if(i>0) up=dp[i-1][j];
//                     if(j>0) left=dp[i][j-1];
//                     dp[i][j]=up+left;
//                 }
//             }
//         }
//         return dp[m-1][n-1];
//     }
// };
// ================================SPACE OPTIMIZATION
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> prev(n, 0);
        for(int i=0; i<m; i++)
        {
            vector<int> temp(n, 0);
            for(int j=0; j<n; j++)
            {
                if(i==0 && j==0) 
                {
                    temp[j]=1;
                    continue;
                }
                int left=0, up=0;
                if(i>0) up=prev[j];
                if(j>0) left=temp[j-1];
                temp[j]=left+up;
            }
            prev=temp;
        }
        return prev[n-1];
    }
};