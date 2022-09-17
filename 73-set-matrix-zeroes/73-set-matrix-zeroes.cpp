class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<int> r, c;
        for(int i=0; i<matrix.size(); i++)
        {
            for(int j=0; j<matrix[i].size(); j++)
            {
                if(matrix[i][j]==0) 
                {
                    r.push_back(i);
                    c.push_back(j);
                }
            }
        }
        for(int x:r) cout<<x<<" ";
        cout<<endl;
        for(int x:c) cout<<x<<" ";
        cout<<endl;
        for(int i=0; i<r.size(); i++)
        {
            for(int j=0; j<matrix[r[i]].size(); j++)
            {
                matrix[r[i]][j]=0;
            }
        }
        for(int i=0; i<c.size(); i++)
        {
            for(int j=0; j<matrix.size(); j++)
            {
                matrix[j][c[i]]=0;
            }
        }
    }
};