class Solution {
public:
    void recursionSum(int i, int target, vector<int> &temp, vector<vector<int>> &ans, vector<int> candidates) {
        if(i==candidates.size())
        {
            if(target==0)
            {
                for(int x:temp) cout<<x<<" ";
                cout<<endl;
                ans.push_back(temp);
            }
            return;
        }
        temp.push_back(candidates[i]);
        if(candidates[i]<=target) recursionSum(i, target-candidates[i], temp, ans, candidates);
        temp.pop_back();
        recursionSum(i+1, target, temp, ans, candidates);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        recursionSum(0, target, temp, ans, candidates);
        
        return ans;
    }
};