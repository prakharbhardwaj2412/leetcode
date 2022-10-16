//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  vector<int> shortestPathBFS(int V, vector<pair<int, int>> adj[]) {
      vector<int> dist(V, INT_MAX);
      vector<int> vis(V, 0);
      dist[0]=0;
      
      queue<int> q;
      q.push(0);
      
      while(!q.empty()) {
          int nd=q.front();
          q.pop();
          for(auto it:adj[nd]) {
              if(!vis[it.first]) {
                  vis[it.first]=1;
                  q.push(it.first);
              }
              dist[it.first] = min(dist[it.first], dist[nd]+it.second);
              
          }
      }
      for(int i=1; i<V; i++) if(vis[i]==0) dist[i]=-1;
      return dist;
  }
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        vector<pair<int, int>> adj[N];
        for(int i=0; i<M; i++) 
            adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
        return shortestPathBFS(N, adj);
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends