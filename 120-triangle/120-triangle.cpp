// // =============================RECURSION
// class Solution {
// public:
//     int f(int row, int col, vector<vector<int>> &triangle)
//     {
//         if(row==triangle.size()-1) return triangle[row][col];
//         int left=f(row+1, col, triangle);
//         int right=f(row+1, col+1, triangle);
//         return min(left, right)+triangle[row][col];
//     }
//     int minimumTotal(vector<vector<int>>& triangle) {
//         return f(0, 0, triangle);
//     }
// };

// =============================MEMOIZATION
// class Solution {
// public:
//     int f(int row, int col, vector<vector<int>> &triangle, vector<vector<int>> &dp)
//     {
//         if(row>=triangle.size()) return 0;
//         if(dp[row][col]!=-1) return dp[row][col];
//         int left=f(row+1, col, triangle, dp);
//         int right=f(row+1, col+1, triangle, dp);
//         return dp[row][col]=min(left, right)+triangle[row][col];
//     }
//     int minimumTotal(vector<vector<int>>& triangle) {
//         int n=triangle.size();
//         int m=triangle[n-1].size();
//         vector<vector<int>> dp(n, vector<int>(m, -1));
//         f(0, 0, triangle, dp);
//         return dp[0][0];
//     }
// };

// // =============================TABULATION
// class Solution {
// public:
//     int minimumTotal(vector<vector<int>>& triangle) {
//         int n=triangle.size();
//         int m=triangle[n-1].size();
//         vector<vector<int>> dp(n, vector<int>(m, -1));
//         for(int j=0; j<m; j++)
//             dp[n-1][j]=triangle[n-1][j];
//         for(int i=n-2; i>=0; i--) {
//             for(int j=i; j>=0; j--) {
//                 int down=triangle[i][j] + dp[i+1][j];
//                 int diagonal=triangle[i][j] + dp[i+1][j+1];
//                 dp[i][j]=min(down, diagonal);
//             }
//         }
//         return dp[0][0];
//     }
// };

// =============================SPACE OPTIMIZATION
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        int m=triangle[n-1].size();
        vector<int> dp(m);
        for(int j=0; j<m; j++)
            dp[j]=triangle[n-1][j];
        for(int i=n-2; i>=0; i--) {
            vector<int> temp(m);
            for(int j=i; j>=0; j--) {
                int down=triangle[i][j] + dp[j];
                int diagonal=triangle[i][j] + dp[j+1];
                temp[j]=min(down, diagonal);
            }
            dp=temp;
        }
        return dp[0];
    }
};