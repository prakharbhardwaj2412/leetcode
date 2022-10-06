// // =============================RECURSION
// class Solution {
// public:
//     int f(int row, int col, vector<vector<int>> &triangle)
//     {
//         if(row>=triangle.size()) return 0;
//         int left=f(row+1, col, triangle);
//         int right=f(row+1, col+1, triangle);
//         return min(left, right)+triangle[row][col];
//     }
//     int minimumTotal(vector<vector<int>>& triangle) {
//         return f(0, 0, triangle);
//     }
// };

// =============================MEMOIZATION
class Solution {
public:
    int f(int row, int col, vector<vector<int>> &triangle, vector<vector<int>> &dp)
    {
        if(row>=triangle.size()) return 0;
        if(dp[row][col]!=-1) return dp[row][col];
        int left=f(row+1, col, triangle, dp);
        int right=f(row+1, col+1, triangle, dp);
        return dp[row][col]=min(left, right)+triangle[row][col];
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        int m=triangle[n-1].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        f(0, 0, triangle, dp);
        return dp[0][0];
    }
};