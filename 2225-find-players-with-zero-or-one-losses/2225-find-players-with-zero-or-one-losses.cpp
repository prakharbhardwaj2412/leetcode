class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int, int> mpp;
        
        for(auto match : matches) {
            if(mpp.find(match[0]) == mpp.end()) mpp[match[0]] = 0;
            mpp[match[1]]++;
        }
        
        vector<vector<int>> ans(2);
        for(auto it : mpp) {
            if(it.second == 0) ans[0].push_back(it.first);
            else if(it.second == 1) ans[1].push_back(it.first);
            
        }
        
        return ans;
    }
};