class Solution {
public:
    bool detectCycleDFS(int node, vector<int> adjLi[], vector<int> &vis, vector<int> &pathVis)
    {
        vis[node]=1;
        pathVis[node]=1;
        for(auto adjNode:adjLi[node])
        {
            if(!vis[adjNode])
            {
                if(detectCycleDFS(adjNode, adjLi, vis, pathVis) == true) return true;
            }
            else if(pathVis[adjNode]) return true;
        }
        pathVis[node]=0;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adjLi[numCourses];
        for(int i=0; i<prerequisites.size(); i++)
            adjLi[prerequisites[i][0]].push_back(prerequisites[i][1]);
        
        vector<int> vis(numCourses, 0);
        vector<int> pathVis(numCourses, 0);
        for(int i=0; i<numCourses; i++)
        {
            if(!vis[i])
                if(detectCycleDFS(i, adjLi, vis, pathVis)) return false;
        }
        return true;
    }
};