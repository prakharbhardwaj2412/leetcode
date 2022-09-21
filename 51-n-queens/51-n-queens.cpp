class Solution {
public:
    void solve(int col, int n, vector<string>& block, vector<vector<string>> &ans) {
        if(col==n)
        {
            ans.push_back(block);
            return;
        }
        for(int row=0; row<n; row++)
        {
            if(isValid(block, row, col, n))
            {
                block[row][col]='Q';
                solve(col+1, n, block, ans);
                block[row][col]='.';
            }
        }
    }
    bool isValid(vector<string> block, int row, int col, int n)
    {
        int r=row, c=col;
        while(r>=0 && c>=0)
        {
            if(block[r][c]=='Q') return false;
            r--; c--;
        }
        r=row; c=col;
        while(c>=0)
        {
            if(block[r][c]=='Q') return false;
            c--;
        }
        r=row; c=col;
        while(c>=0 && r<n)
        {
            if(block[r][c]=='Q') return false;
            c--; r++;
        }
        return true;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> block;
        string s(n, '.');
        cout<<s;
        for(int i=0; i<n; i++) block.push_back(s);
        solve(0, n, block, ans);
        return ans;
    }
};