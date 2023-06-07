//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  private:
    void dfs(int par, bool vis[], vector<int> g[]){
        vis[par] = 1;
        for (int child : g[par]){
            if (vis[child]) continue;
            dfs(child, vis, g);
        }
    }
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        vector<int> g[V];
        for (int i=0; i<adj.size(); i++){
            for (int j=0; j<adj[i].size(); j++){
                if (adj[i][j] == 1 && i != j){
                    g[i].push_back(j);
                    g[j].push_back(i);
                }
            }
        }
        bool vis[V];
        memset(vis, false, sizeof(vis));
        int c = 0;
        for (int i=0; i<V; i++) if (!vis[i]) dfs(i, vis, g), c++;
        return c;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends