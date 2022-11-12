class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int insertIndex=0, zero=0;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i]==0) zero++;
            if(nums[i] != 0) nums[insertIndex++]=nums[i];
        }
        for(int i=nums.size()-zero; i<nums.size(); i++) {
            nums[i]=0;
        }
        
    }
};