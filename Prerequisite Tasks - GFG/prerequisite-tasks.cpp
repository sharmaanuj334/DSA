//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool dfs(int par, vector<int> adj[], vector<bool> &vis, vector<bool> &path){
        vis[par] = 1;
        path[par] = 1;
        for (int child : adj[par]){
            if (vis[child] && path[child]) return true;
            if (!vis[child]) if (dfs(child, adj, vis, path)) return true;
        }
        path[par] = 0;
        return false;
    }
	bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
	    vector<int> adj[N];
	    for (auto it : prerequisites){
	        adj[it.first].push_back(it.second);
	    }
	    vector<bool> vis(N, false), path(N, false);
	    for (int i=0; i<N; i++){
	        if (!vis[i]){
	            if (dfs(i, adj, vis, path)) return false;
	        }
	    }
	    return true;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends