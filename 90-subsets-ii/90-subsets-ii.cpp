class Solution {
public:
    void returnSubset(int ind, vector<int> &arr, set<vector<int>> &ans, vector<int> &ds) {
        if(ind==arr.size())
        {
            ans.insert(ds);
            return;
        }
        ds.push_back(arr[ind]);
        returnSubset(ind+1, arr, ans, ds);
        ds.pop_back();
        returnSubset(ind+1, arr, ans, ds);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> ans;
        vector<int> ds;
        sort(nums.begin(), nums.end());
        returnSubset(0, nums, ans, ds);
        vector<vector<int>> v(ans.begin(), ans.end());
        return v;
    }
};