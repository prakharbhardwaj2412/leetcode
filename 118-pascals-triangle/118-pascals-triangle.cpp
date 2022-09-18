class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        vector<int> t;
        t.push_back(1);
        ans.push_back(t);
        t.push_back(1);
        if(numRows>1) ans.push_back(t);
        
        for(int i=3; i<=numRows; i++)
        {
            vector<int> temp(i);
            temp[0]=1;
            int j;
            for(j=0; j<ans[i-2].size()-1; j++)
            {
                temp[j+1]=ans[i-2][j]+ans[i-2][j+1];
            }
            temp[j+1]=1;
            ans.push_back(temp);
            
        }
        return ans;
    }
};