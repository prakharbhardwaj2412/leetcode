class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0, maxi=nums[0], n=nums.size();
        
        for(int it:nums)
        {
            sum+=it;
            maxi=max(maxi, sum);
            sum=max(sum, 0);
        }
        return maxi;
    }
};

// KADANE'S ALGO