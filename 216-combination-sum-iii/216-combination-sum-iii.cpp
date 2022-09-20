class Solution {
public:
    void recursionSum(int index, int target, vector<int> &temp, vector<vector<int>> &ans, vector<int> arr, int k) {
        if(target==0)
        {
            if(temp.size()==k) ans.push_back(temp);
            return;
        }
        for(int i=index; i<arr.size(); i++)
        {
            if(i>index && arr[i]==arr[i-1]) continue;
            if(arr[i]>target) break;
            temp.push_back(arr[i]);
            recursionSum(i+1, target-arr[i], temp, ans, arr, k);
            temp.pop_back();
        }
        
        
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> temp;
        vector<int> arr={1, 2, 3, 4, 5, 6, 7, 8, 9};
        recursionSum(0, n, temp, ans, arr, k);
        vector<vector<int>> v(ans.begin(), ans.end());        
        return ans;
        
    }
};