class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low=0, mid=0, high=nums.size()-1;
        while(mid<=high)
        {
            for(auto x:nums) cout<<x<<" ";
            cout<<endl;
            if(nums[mid]==0)
            {
                swap(nums[mid], nums[low]);
                mid++; low++;
            }
            else if(nums[mid]==2)
            {
                swap(nums[mid], nums[high]);
                // mid++;
                high--;
            }
            else if(nums[mid]==1) mid++;
        }
        
    }
    // void swap(int &a, int &b)
    // {
    //     int temp=b;
    //     b=a;
    //     a=temp;
    // }
};