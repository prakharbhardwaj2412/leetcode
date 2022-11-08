class Solution {
public:
    void dfs(int ind, int dest, vector<vector<int>> &ans, vector<vector<int>> graph, vector<int> &temp) {
        if(ind == dest) ans.push_back(temp);
        for(auto it:graph[ind]) {
            temp.push_back(it);
            dfs(it, dest, ans, graph, temp);
            temp.pop_back();
        }
    }
    void bfs(int V, vector<vector<int>> graph, vector<vector<int>> &ans) {
        vector<int> temp;
        temp.push_back(0);
        queue<pair<int, vector<int>>> q;
        q.push({0, {0}});
        while(!q.empty()) {
            int node = q.front().first;
            temp = q.front().second;
            q.pop();
            if(temp[temp.size()-1] == V-1) ans.push_back(temp);
            for(auto it : graph[node]) {
                temp.push_back(it);
                q.push({it, temp});
                temp.pop_back();
            }
        } 
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        int V = graph.size();
        vector<int> temp;
        temp.push_back(0);
        // dfs(0, V-1, ans, graph, temp);
        bfs(V, graph, ans);
        return ans;
        
    }
};