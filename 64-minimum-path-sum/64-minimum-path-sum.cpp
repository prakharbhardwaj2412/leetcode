class Solution {
public:
    // int f() {
    //     if(i==0 && j==0) return grid[0][0];
    //     if(i<0 || j<0) return 0;
    //     int up=f(i-1, j, sum);
    //     int 
    // }
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(i==0 && j==0) dp[i][j]=grid[i][j];
                else {
                    int left=INT_MAX, up=INT_MAX;
                    if(i>0) left=dp[i-1][j];
                    if(j>0) up=dp[i][j-1];
                    dp[i][j]=grid[i][j]+min(left, up);
                }
            }
        }
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) cout<<dp[i][j]<<" ";
            cout<<endl;
        }
        return dp[n-1][m-1];
    }
};