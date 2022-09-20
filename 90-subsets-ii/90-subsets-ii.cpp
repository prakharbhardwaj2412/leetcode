class Solution {
public:
    void returnSubset(int ind, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds) {
        if(ind==arr.size())
        {
            // ans.push_back(ds);
            return;
        }
        for(int i=ind; i<arr.size(); i++)
        {
            if(i>ind && arr[i]==arr[i-1]) continue;
            ds.push_back(arr[i]);
            ans.push_back(ds);
            returnSubset(i+1, arr, ans, ds);
            ds.pop_back();
        }
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        ans.push_back(ds);
        sort(nums.begin(), nums.end());
        returnSubset(0, nums, ans, ds);
        // vector<vector<int>> v(ans.begin(), ans.end());
        return ans;
    }
};