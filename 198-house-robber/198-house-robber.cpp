// TABULATION
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n);
        dp[0]=nums[0];
        for(int i=1; i<nums.size(); i++)
        {
            int pick=nums[i]; 
            if(i>1) pick+=dp[i-2];
            int notPick=0+dp[i-1];
            dp[i]=max(pick, notPick);
        }
        return dp[n-1];
    }
};
// SPACE OPTIMIZED DP
// class Solution {
// public:
//     int rob(vector<int>& nums) {
//         int prev=nums[0];
//         int prev2=0;
//         for(int i=1; i<nums.size(); i++)
//         {
//             int pick=nums[i]; 
//             if(i>1) pick+=prev2;
//             int notPick=0+prev;
//             int curri=max(pick, notPick);
//             prev2=prev;
//             prev=curri;
//         }
//         return prev;
//     }
// };