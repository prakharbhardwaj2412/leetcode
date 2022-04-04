class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int l = nums.size(), temp=0;
        
        for (int i=nums.size()-1; i>0; i--)
        {
            if(nums[i]>nums[i-1]) 
            {
                int j=0;
                for(j=l-1; j>i-1; j--)
                {
                    if(nums[j]>nums[i-1]) break;
                }
                temp = nums[j];
                nums[j] = nums[i-1];
                nums[i-1] = temp;
                partial_sort(nums.begin()+i, nums.end(), nums.end());
                return;
            }
        }
        reverse(nums.begin(), nums.end());
        return;
        
    }
};