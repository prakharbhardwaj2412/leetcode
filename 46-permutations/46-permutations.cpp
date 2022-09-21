class Solution {
public:
    void makePermutation(int ind, vector<int>& nums, vector<int> &ds, vector<vector<int>> &ans, int freq[]) {
        if(ind==nums.size()) {
            ans.push_back(ds);
            return;
        }
        for(int i=0; i<nums.size(); i++) {
            if(!freq[i]) {
                freq[i]=1;
                ds.push_back(nums[i]);
                makePermutation(ind+1, nums, ds, ans, freq);
                freq[i]=0;
                ds.pop_back();
            }
        }
        
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int freq[nums.size()];
        for(int i=0; i<nums.size(); i++) freq[i]=0;
        vector<int> ds;
        makePermutation(0, nums, ds, ans, freq);
        return ans;
    }
};