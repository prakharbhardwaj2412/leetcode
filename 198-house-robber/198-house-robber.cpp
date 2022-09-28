// MEMOIZATION
class Solution {
public:
    int f(int ind, vector<int> &nums, vector<int> &dp)
    {
        if(ind<0) return 0;
        if(dp[ind]!=-1) return dp[ind];
        int pick=nums[ind]+f(ind-2, nums, dp);
        int notPick=0+f(ind-1, nums, dp);
        return dp[ind]=max(pick, notPick);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n, -1);
        f(n-1, nums, dp);
        return dp[n-1];
    }
};
// // TABULATION
// class Solution {
// public:
//     int rob(vector<int>& nums) {
//         int n=nums.size();
//         vector<int> dp(n);
//         dp[0]=nums[0];
//         for(int i=1; i<nums.size(); i++)
//         {
//             int pick=nums[i]; 
//             if(i>1) pick+=dp[i-2];
//             int notPick=0+dp[i-1];
//             dp[i]=max(pick, notPick);
//         }
//         return dp[n-1];
//     }
// };
// // SPACE OPTIMIZED DP
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