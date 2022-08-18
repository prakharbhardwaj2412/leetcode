class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int i=0, j=nums.size()-1;
        vector<int> res;
        while(i<=j)
        {
            if(nums[i]==target && nums[j]==target) break;
            if(nums[i]!=target) i++;
            if(nums[j]!=target) j--;
        }
        cout<<i<<" "<<j<<endl;
        if(j<i)
        {
            res.push_back(-1);
            res.push_back(-1);
        }
        else 
        {
            res.push_back(i);
            res.push_back(j);
        }
        return res;
    }
};