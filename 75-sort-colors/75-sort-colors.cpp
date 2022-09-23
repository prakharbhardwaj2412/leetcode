class Solution {
public:
    void sortColors(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return;
        int low=0, mid=0, high=nums.size()-1;
        for(mid=0; mid<=high; )
        {
            if(nums[mid]==0)
            {
                swap(nums[low], nums[mid]);
                low++; mid++;
            }
            else if(nums[mid]==2)
            {
                swap(nums[mid], nums[high]);
                high--;
            }
            else mid++;
        }
        
    }
    void swap(int &a, int &b)
    {
        int temp=b;
        b=a;
        a=temp;
    }
};