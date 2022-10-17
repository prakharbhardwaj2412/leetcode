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
  void topoSortDFS(int node, vector<int> &vis, stack<int> &st, vector<pair<int, int>> adj[]) {
      vis[node]=1;
      for(auto it:adj[node]) {
          if(!vis[it.first]) {
              topoSortDFS(it.first, vis, st, adj);
          }
      }
      st.push(node);
  }
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        vector<pair<int, int>> adj[N];
        for(int i=0; i<M; i++) 
        {
            int u=edges[i][0], v=edges[i][1], wt=edges[i][2];
            adj[u].push_back({v, wt});
        }
        
        // return shortestPathBFS(N, adj);
        vector<int> vis(N, 0);
        stack<int> st;
        for(int i=0; i<N; i++) {
            if(!vis[i]) topoSortDFS(i, vis, st, adj);
        }
        
        vector<int> dist(N, 1e9);
        dist[0]=0;
        while(!st.empty()) {
            int node=st.top();
            st.pop();
            
            for(auto it:adj[node]) {
                int v=it.first;
                int wt=it.second;
                dist[v] = min(dist[v], dist[node]+wt);
            }
        }
        for(int i=0; i<N; i++) if(dist[i]==1e9) dist[i]=-1;
        return dist;
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