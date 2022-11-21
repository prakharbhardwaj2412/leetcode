class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size(), n = maze[0].size();
        queue<pair<pair<int, int>, int>> q;
        q.push({{entrance[0], entrance[1]}, 0});
        
        vector<vector<int>> vis(m, vector<int>(n, 0));
        vis[entrance[0]][entrance[1]] = 1;
        
        int delrow[] = {-1, 0, +1, 0};
        int delcol[] = {0, +1, 0, -1};
        
        while(!q.empty()) {
            auto it = q.front();
            q.pop();
            int row = it.first.first;
            int col = it.first.second;
            int exit = it.second;
            
            cout<<row<<" "<<col<<" "<<exit<<endl;
            
            // maze[row][col] = '+';
            // vis[row][col] = 1;
            
            for(int i = 0; i < 4; i++) {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                
                if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && maze[nrow][ncol] != '+' && !vis[nrow][ncol]) {
                    if(nrow == 0 || nrow == m - 1 || ncol == 0 || ncol == n - 1) return exit + 1;
                    vis[nrow][ncol] = 1;
                    q.push({{nrow, ncol}, exit + 1});
                }
            }
            
        }
        return -1;
    }
};