class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int insertIndex=0;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i]!=val) {
                nums[insertIndex++]=nums[i];
            }
        }
        return insertIndex;
    }
};