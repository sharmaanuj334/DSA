//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]){
        vector<int> inDegree(V, 0);
        vector<int> g[V];
        for (int i=0; i<V; i++){
            for (int j=0; j<adj[i].size(); j++){
                g[adj[i][j]].push_back(i);
                inDegree[i]++;
            } 
        }
        queue<int> q;
        for (int i=0; i<V; i++) if (inDegree[i] == 0) q.push(i);
        vector<int> ans;
        while (!q.empty()){
            int par = q.front();
            ans.push_back(par);
            q.pop();
            for (int child : g[par]){
                inDegree[child]--;
                if (inDegree[child] == 0) q.push(child);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
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