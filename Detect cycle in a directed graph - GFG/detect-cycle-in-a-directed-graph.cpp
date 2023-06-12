//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
    bool dfs(int par, vector<int> adj[], vector<bool> &vis, vector<bool> &path){
        vis[par] = 1;
        path[par] = 1;
        for (int child : adj[par]){
            if (vis[child] && path[child]) return true;
            if (vis[child]) continue;
            if (dfs(child, adj, vis, path)) return true;
        }
        path[par] = 0;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        vector<bool> vis(V, false), path(V, false);
        for (int i=0; i<V; i++){
            if (!vis[i]){
                if (dfs(i, adj, vis, path)) return true;
            }
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