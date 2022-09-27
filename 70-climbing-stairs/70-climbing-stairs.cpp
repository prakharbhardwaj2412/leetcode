class Solution {
public:
    int climbStairs(int n) {
        unsigned int a=1, b=1;
        for(int i=0; i<n; i++)
        {
            unsigned int temp=a;
            a=b;
            b=temp+b;
        }
        return a;
    }
};