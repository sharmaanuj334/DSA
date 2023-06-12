//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  private:
    bool dfs(int par, vector<int> adj[], vector<bool> &vis, vector<bool> &path, vector<int> &valid){
        vis[par] = 1;
        path[par] = 1;
        for (int child : adj[par]){
            if (vis[child] && path[child]) return true;
            if (vis[child]) continue;
            if (dfs(child, adj, vis, path, valid) == true){
                return true;
            } else{
                valid.push_back(child);
            }
        }
        path[par] = 0;
        return false;
    }
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]){
        vector<bool> vis(V, false), path(V, false);
        vector<int> valid;
        for (int i=0; i<V; i++){
            if (!vis[i]){
                if (dfs(i, adj, vis, path, valid) == false){
                    valid.push_back(i);
                }
            }
        }
        sort(valid.begin(), valid.end());
        return valid;
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
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends