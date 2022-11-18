class Solution {
private:
    void dfs(int row, int col, vector<vector<char>> &board, vector<vector<char>> &temp){
        int n=board.size();
        int m=board[0].size();
        // if(row<0 || row>=n || col<0 || col>=m) return;
        
        temp[row][col]='O';
        
        int delrow[]={-1, 0, 1, 0};
        int delcol[]={0, 1, 0, -1};
        for(int i=0; i<4; i++)
        {
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m)
            {
                if(board[nrow][ncol]=='O' && temp[nrow][ncol]!='O') {
                    dfs(nrow, ncol, board, temp);
                }
            }
        }
        
        
    }
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<char>> temp(n, vector<char>(m, 'X'));
        for(int i=0; i<n; i++)
        {
            if(board[i][0]=='O')
                dfs(i, 0, board, temp);
            
            if(board[i][m-1]=='O')
                dfs(i, m-1, board, temp);
        }
        for(int i=0; i<m; i++)
        {
            if(board[0][i]=='O')
                dfs(0, i, board, temp);
            if(board[n-1][i]=='O')
                dfs(n-1, i, board, temp);
        }
        board=temp;
    }
};