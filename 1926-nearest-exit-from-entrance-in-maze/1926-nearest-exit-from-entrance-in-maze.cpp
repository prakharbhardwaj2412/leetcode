class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size(), n = maze[0].size();
        
        // Start BFS from the entrance, and use a queue `queue` to store all 
        // the cells to be visited.
        queue<pair<pair<int, int>, int>> q; // {{row, col}, exit_count}
        q.push({{entrance[0], entrance[1]}, 0});
        
        // Mark the entrance as visited since its not a exit.
        maze[entrance[0]][entrance[1]] = '+';
        
        int delrow[] = {-1, 0, +1, 0};
        int delcol[] = {0, +1, 0, -1};
        
        while(!q.empty()) {
            auto it = q.front();
            q.pop();
            int row = it.first.first;
            int col = it.first.second;
            int exit = it.second;
            
            // For the current cell, check its four neighbor cells.
            for(int i = 0; i < 4; i++) {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                
                // If there exists an unvisited empty neighbor:
                if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && maze[nrow][ncol] != '+') {
                    
                    // If this empty cell is an exit, return distance + 1.
                    if(nrow == 0 || nrow == m - 1 || ncol == 0 || ncol == n - 1) return exit + 1;
                    
                    // Otherwise, add this cell to 'queue' and mark it as visited.
                    maze[nrow][ncol] = '+';
                    q.push({{nrow, ncol}, exit + 1});
                }
            }
            
        }
        // If we finish iterating without finding an exit, return -1.
        return -1;
    }
};

// QUES - Why BFS over Depth First Search (DFS) for this problem?

// ANS - The reason is that DFS is not guaranteed to find the shortest path, 
// as it will explore the matrix as much as possible before moving on to another branch.