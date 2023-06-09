//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  private:
  bool dfs(int par, int gp, vector<int> adj[], vector<bool> &vis){
      vis[par] = 1;
      for (int child : adj[par]){
          if (vis[child] && child != gp) return true;
          if (!vis[child]) if (dfs(child, par, adj, vis)) return true;
      }
      return false;
  }
  public:
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool> vis(V, false);
        for (int i=0; i<V; i++){
            if (!vis[i]) if(dfs(i, -1, adj, vis)) return true;
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends