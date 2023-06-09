//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  private:
  bool detect(int s, vector<int> adj[], vector<bool> &vis){
        queue<pair<int,int>> q;
        q.push({s, -1});
        while (!q.empty()){
            int par = q.front().first;
            int gp = q.front().second;
            q.pop();
            vis[par] = 1;
            for (int child : adj[par]){
                if (vis[child] && child != gp){
                    return true;
                } else if (!vis[child]){
                    q.push({child, par});
                }
            }
        }
        return false;
  }
  public:
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool> vis(V, false);
        bool c = false;
        for (int i=0; i<V; i++){
            if (!vis[i]) c |= detect(i, adj, vis);
            if (c) return true;
        }
        return c;
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