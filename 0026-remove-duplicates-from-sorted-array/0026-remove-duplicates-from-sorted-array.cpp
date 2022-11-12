class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0, j=1, count=0;
        while(nums.size()>1 && j<nums.size()) {
            if(nums[i] == nums[j]) {
                nums.erase(nums.begin()+j);
            }
            else {
                i++; j++;
                count++;
            }
        }
        return count+1;
    }
};