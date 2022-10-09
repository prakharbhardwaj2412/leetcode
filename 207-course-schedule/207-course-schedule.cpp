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
    // bool detectCycleBFS()
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adjLi[numCourses];
        for(int i=0; i<prerequisites.size(); i++)
            adjLi[prerequisites[i][0]].push_back(prerequisites[i][1]);
        
        vector<int> vis(numCourses, 0);
        vector<int> pathVis(numCourses, 0);
        for(int i=0; i<numCourses; i++) {
            if(vis[i]==0)
                if(detectCycleDFS(i, adjLi, vis, pathVis)) return false;
        }
        return true;
    }
};