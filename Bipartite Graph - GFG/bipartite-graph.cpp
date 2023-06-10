//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
private:
    bool dfs(int par, vector<int> adj[], int vis[]){
        bool c = true;
        for (int child : adj[par]){
            if (vis[child] == vis[par]) return false;
            if (vis[child] == -1){
                vis[child] = (vis[par] == 1) ? 2 : 1;
                c &= dfs(child, adj, vis);
            }
        }
        return c;
    }
public:
	bool isBipartite(int V, vector<int>adj[]){
	    int vis[V]; for (int i=0; i<V; i++) vis[i] = -1;
	    bool c = true;
	    for (int i=0; i<V; i++){
	        if (vis[i] == -1){
	            vis[i] = 1;
	            c &= dfs(i, adj, vis);
	        } 
	    }
	    return c;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends