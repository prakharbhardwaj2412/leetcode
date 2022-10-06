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

// =============================TABULATION
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        int m=triangle[n-1].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        dp[0][0]=triangle[0][0];
        for(int i=1; i<n; i++) {
            for(int j=0; j<triangle[i].size(); j++) {
                int left=INT_MAX, right=INT_MAX;
                if(j==0) {
                    left=INT_MAX;
                    right=dp[i-1][j];
                }
                else if(j==triangle[i-1].size())
                {
                    left=dp[i-1][j-1];
                    right=INT_MAX;
                } else {
                    left=dp[i-1][j-1];
                    right=dp[i-1][j];
                }
                dp[i][j]=min(left, right)+triangle[i][j];
            }
        }
        int mini=INT_MAX;
        for(int i=0; i<m; i++)
            if(mini>dp[n-1][i]) mini=dp[n-1][i];
        return mini;
    }
};