class Solution {
public:
    void sortColors(vector<int>& nums) {
//         VARIATION OF DUTCH NATIONAL FLG ALGORITHM
//         nums[0->low-1]->0
//         nums[high+1->n-1]->2
        int low=0, mid=0, high=nums.size()-1;
        while(mid<=high)
        {
            switch(nums[mid])
            {
                case 0:
                    swap(nums[low++], nums[mid++]);
                    break;
                case 1:
                    mid++;
                    break;
                case 2:
                    swap(nums[mid], nums[high--]);
                    break;
            }
        }
        
    }
};