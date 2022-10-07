class Solution {
public:
    bool detectCycleDFS(int node, vector<int> adjLi[], vector<int> &vis) {
        vis[node]=2;
        // travel for adjacent nodes
        for(auto adjNode:adjLi[node]) {
            // when node is not visited
            if(vis[adjNode]==0) {
                if(detectCycleDFS(adjNode, adjLi, vis) == true) return true;
            }
            // if node has been previously visited
            // but it has to be visited on the same path
            else if(vis[adjNode]==2) return true;
        }
        vis[node]=1;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adjLi[numCourses];
        for(int i=0; i<prerequisites.size(); i++)
            adjLi[prerequisites[i][0]].push_back(prerequisites[i][1]);
        
        vector<int> vis(numCourses, 0);
        // vector<int> pathVis(numCourses, 0);
        for(int i=0; i<numCourses; i++) {
            if(vis[i]==0)
                if(detectCycleDFS(i, adjLi, vis)) return false;
        }
        return true;
    }
};