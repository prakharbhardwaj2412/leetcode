class Solution {
public:
    int thirdMax(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());
        
        vector<int> dp;
        
        int n=nums.size();
        
        for(int i=0; i<n-1; i++)
            if(nums[i] != nums[i+1])
                dp.push_back(nums[i]);
        dp.push_back(nums[n-1]);
        
        if(dp.size()>2) return dp[2];
        else return dp[0];

        
    }
};