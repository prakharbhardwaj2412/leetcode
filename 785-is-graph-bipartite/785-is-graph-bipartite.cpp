class Solution {
private:
    bool bfsCheck(int start, vector<vector<int>> &graph, vector<int> &color) {
        color[start]=0;
        queue<int> q;
        q.push(start);
        while(!q.empty()) {
            int node=q.front();
            q.pop();
            for(auto adjNode:graph[node]) {
                if(color[adjNode]==-1) {
                    color[adjNode]=!color[node];
                    q.push(adjNode);
                } else if(color[adjNode]==color[node]) return false;
            }
        }
        return true;
        
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int V=graph.size();
        vector<int> color(V, -1);
        for(int i=0; i<V; i++) {
            if(color[i]==-1)
                if(bfsCheck(i, graph, color)==false) 
                    return false;
        }
        return true;
    }
};