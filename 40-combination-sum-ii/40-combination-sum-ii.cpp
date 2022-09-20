class Solution {
public:
    void recursionSum(int index, int target, vector<int> &temp, vector<vector<int>> &ans, vector<int> candidates) {
        if(target==0)
        {
            ans.push_back(temp);
            return;
        }
        for(int i=index; i<candidates.size(); i++)
        {
            if(i>index && candidates[i]==candidates[i-1]) continue;
            if(candidates[i]>target) break;
            temp.push_back(candidates[i]);
            recursionSum(i+1, target-candidates[i], temp, ans, candidates);
            temp.pop_back();
        }
        
        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        recursionSum(0, target, temp, ans, candidates);
        vector<vector<int>> v(ans.begin(), ans.end());        
        return ans;
    }
};