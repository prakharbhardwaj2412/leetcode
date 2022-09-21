class Solution {
public:
    void makePermutation(int ind, vector<int>& nums, vector<int> &ds, vector<vector<int>> &ans, unordered_map<int, int> &mp) {
        if(ind==nums.size()) 
        {
            ans.push_back(ds);
            return;
        }
        for(int i=0; i<nums.size(); i++)
        {
            if(mp[nums[i]]==0)
            {
                mp[nums[i]]=1;
                ds.push_back(nums[i]);
                makePermutation(ind+1, nums, ds, ans, mp);
                mp[nums[i]]=0;
                ds.pop_back();
            }
            
            
        }
        
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        unordered_map<int, int> mp;
        vector<int> ds;
        for(int x: nums) mp[x]=0;
        makePermutation(0, nums, ds, ans, mp);
        return ans;
    }
};