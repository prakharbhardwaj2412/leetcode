class Solution {
public:
    void dfs(int ind, int dest, vector<int> &vis, vector<vector<int>> &ans, vector<vector<int>> graph, vector<int> &temp) {
        vis[ind] = 1;
        if(ind == dest) ans.push_back(temp);
        for(auto it:graph[ind]) {
            temp.push_back(it);
            dfs(it, dest, vis, ans, graph, temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        int V = graph.size();
        vector<int> vis(V, 0);
        vector<int> temp;
        temp.push_back(0);
        dfs(0, V-1, vis, ans, graph, temp);
        return ans;
        
    }
};