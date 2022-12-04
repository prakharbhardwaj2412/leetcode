class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n = nums.size(), index = 0;
        long long int sum = 0, sumi = 0, min_avg = LLONG_MAX;
        
        for(int it : nums) sum += it;
        
        for(int i = 0; i < n; i++) {
            sumi += nums[i];
            int f = sumi / (i + 1);
            int l = 0;
            if(n - i - 1 > 0) l = (sum - sumi) / (n - i - 1);
            int avg = abs(f - l);
            if(min_avg > avg) {
                min_avg = avg;
                index = i;
            }
        }
        return index;
    }
};