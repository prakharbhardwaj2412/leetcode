// // ============RECURSION
// class Solution {
// public:
//     int fib(int n) {
//         if(n<=1) return n;
//         return fib(n-1)+fib(n-2);
//     }
// };

// // ==========MEMOIZATION
// class Solution {
// public:
//     int f(int n, vector<int> &dp)
//     {
//         if(n<=1) return n;
//         if(dp[n]!=-1) return dp[n];
//         return dp[n]=f(n-1, dp) + f(n-2, dp);
//     }
//     int fib(int n) {
//         vector<int> dp(n+1, -1);
//         return f(n, dp);
//     }
// };

// // ============TABULATION
// class Solution {
// public:
//     int fib(int n) {
//         vector<int> dp(n+1);
//         if(n==0) return 0;
//         dp[0]=0; dp[1]=1;
//         for(int i=2; i<=n; i++)
//             dp[i]=dp[i-1]+dp[i-2];
//         return dp[n];
//     }
// };

// // ===============SPACE OPTIMIZATION
class Solution {
public:
    int fib(int n) {
        if(n==0) return 0;
        int prev=1, prev2=0;
        for(int i=2; i<=n; i++)
        {
            int current_i=prev+prev2;
            prev2=prev;
            prev=current_i;
        }
        return prev;
    }
};