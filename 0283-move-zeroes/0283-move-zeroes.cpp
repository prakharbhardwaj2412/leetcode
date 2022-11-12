class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int insertIndex=0;
        // for(int i=0; i<nums.size(); i++) {
        //     if(nums[i] != 0) nums[insertIndex++]=nums[i];
        // }
        // for(int i=insertIndex; i<nums.size(); i++) {
        //     nums[i]=0;
        // }
        for(int i=0; i<nums.size(); i++) {
            if(nums[i]!=0) swap(nums[i], nums[insertIndex++]);
        }
    }
};