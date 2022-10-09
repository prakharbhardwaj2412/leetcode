class Solution {
public:
    bool detectCycleDFS(int node, vector<int> adjLi[], vector<int> &vis, vector<int> &pathVis) {
        vis[node]=1;
        pathVis[node]=1;
        // travel for adjacent nodes
        for(auto adjNode:adjLi[node]) {
            // when node is not visited
            if(!vis[adjNode]) {
                if(detectCycleDFS(adjNode, adjLi, vis, pathVis) == true) return true;
            }
            // if node has been previously visited
            // but it has to be visited on the same path
            else if(pathVis[adjNode]) return true;
        }
        pathVis[node]=0;
        return false;
    }
//     BFS algo to detect cycle in directed graph || Khan's Algorithm || Topological Sort
    bool detectCycleBFS(int V, vector<int> adjLi[]) {
        vector<int> indegree(V, 0);
        for(int i=0; i<V; i++) {
            for(int it:adjLi[i]) 
                indegree[it]++;
        }
        queue<int> q;
        for(int i=0; i<V; i++) {
            if(indegree[i]==0) q.push(i);
        }
        int countNode=0;
        while(!q.empty()) {
            int node=q.front();
            q.pop();
            countNode++;
            for(int it:adjLi[node]) {
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
        if(countNode==V) return false;
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adjLi[numCourses];
        for(int i=0; i<prerequisites.size(); i++)
            adjLi[prerequisites[i][0]].push_back(prerequisites[i][1]);
        
//         DFS function to detect cycle in a graph
        vector<int> vis(numCourses, 0);
        vector<int> pathVis(numCourses, 0);
        for(int i=0; i<numCourses; i++) {
            if(vis[i]==0)
                if(detectCycleDFS(i, adjLi, vis, pathVis)) return false;
        }
        return true;
//         BFS function to detect cycle in a graph
        return !detectCycleBFS(numCourses, adjLi);
    }
};