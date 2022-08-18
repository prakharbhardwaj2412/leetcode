class Solution {
public:
    int search(vector<int>& nums, int target) {
        int mid=0, l, h;
        for(h=0; h<nums.size()-1; h++)
            if(nums[h]>nums[h+1]) break;
        
        while(l<h)
        {
            mid=(l+h)/2;
            if(nums[mid]>nums[h]) l=mid+1;
            else h=mid;
        }
        cout<<mid<<" "<<l<<" "<<h<<endl;
        
        
        
        
        
        l=h+1;
        if(nums[mid]==target) return mid;
        else if(nums[mid]<target) l=mid+1;
        else h=nums.size()-1;
        while(l<=h)
        {
            mid=(l+h)/2;
            if(nums[mid]==target) return mid;
            else if(nums[mid]<target) l=mid+1;
            else h=mid-1;
        }
        return -1;
    }
};