class Solution {
public:
    
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        int ans1, ans2;
        int prev=nums[0];
        int prev2=0;
        for(int i=1; i<nums.size()-1; i++)
        {
            int pick=nums[i]; 
            if(i>1) pick+=prev2;
            int notPick=0+prev;
            int curri=max(pick, notPick);
            prev2=prev;
            prev=curri;
        }
        ans1=prev;
        
        prev=nums[1];
        prev2=0;
        for(int i=2; i<nums.size(); i++)
        {
            int pick=nums[i]; 
            if(i>2) pick+=prev2;
            int notPick=0+prev;
            int curri=max(pick, notPick);
            prev2=prev;
            prev=curri;
        }
        ans2=prev;
        return max(ans1, ans2);
    }
};