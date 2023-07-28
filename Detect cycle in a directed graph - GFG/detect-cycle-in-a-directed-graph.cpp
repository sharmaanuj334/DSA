//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool dfs(int par, int vis[], int path[], vector<int> g[]){
        vis[par] = 1;
        path[par] = 1;
        for (int child : g[par]){
            if (vis[child] && path[child]) return true;
            if (vis[child]) continue;
            // path[child] = 1;
            if (dfs(child, vis, path, g)) return true;
        }
        path[par] = 0;
        return false;
    }
    bool isCyclic(int n, vector<int> adj[]){
        int vis[n]; int path[n];
        memset(vis, 0, sizeof(vis)); memset(vis, 0, sizeof(vis));
        for (int i=0; i<n; i++){
            if (!vis[i]) if (dfs(i, vis, path, adj)) return true;
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends