class Solution {
public:
    int countPrimes(int n) {
        vector<bool> prime(n+1, true);
        
        int p = 2;
        while(p * p <= n) {
            if(prime[p] == true) {
                for(int i = p * p; i < n + 1; i+=p) prime[i] = false;
            }
            p++;
        }
        
        int c = 0;
        for(int i=2; i < n; i++) if(prime[i]) c++;
        return c;
    }
//     fun to check prime number
//     bool isPrime(int n)
//     {
//         // Corner case
//         if (n <= 1)
//             return false;

//         // Check from 2 to n-1
//         if(n % 2 == 0) return n == 2;
//         int max_div = floor(sqrt(n));
//         for (int i = 2; i <= max_div; i++)
//             if (n % i == 0)
//                 return false;

//         return true;
//     }
};