class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i=0, n=nums.size();
        int sum=(n*(n+1))/2;
        for(i=0; i<nums.size(); i++){
            sum-=nums[i];
        }
        return sum;
    }
};