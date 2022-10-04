class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<int> dp(n, 0);
        for(int i=0; i<m; i++)
        {
            vector<int> temp(n, 0);
            for(int j=0; j<n; j++)
            {
                
                if(i==0 && j==0) temp[j]=1;
                else 
                {
                    int left=0, up=0;
                    if(i>0) up=dp[j];
                    if(j>0) left=temp[j-1];
                    temp[j]=left+up;
                }
                if(obstacleGrid[i][j]==1) temp[j]=0;
            }
            dp=temp;
        }
        return dp[n-1];
        
    }
};