class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n=nums.size();
        int curSum=0, closest=nums[0]+nums[1]+nums[2];
        sort(nums.begin(), nums.end());
        int start, end, mid;
        for(int start=0; start<n-2; start++) {
            mid=start+1, end=n-1;
            while(mid<end) {
                curSum=nums[start]+nums[mid]+nums[end];
                if(curSum==target) return curSum;
                if(abs(target-curSum)<abs(target-closest)) closest=curSum;
                if(curSum<target) mid++;
                if(curSum>target) end--;
            }
        }
        return closest;
    }
};