//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	void dfs1(int par, vector<vector<int>> &g, stack<int> &st, vector<bool> &vis1){
	    vis1[par] = 1;
	    for (int child : g[par]){
	        if (vis1[child]) continue;
	        dfs1(child, g, st, vis1);
	    }
	    st.push(par);
	}
	void dfs2(int par, vector<int> r[], vector<bool> &vis2){
	    vis2[par] = 1;
	    for (int child : r[par]){
	        if (vis2[child]) continue;
	        dfs2(child, r, vis2);
	    }
	}
    int kosaraju(int V, vector<vector<int>>& g){
        vector<int> r[V];
        for (int i=0; i<g.size(); i++){
            for (int j=0; j<g[i].size(); j++){
                r[g[i][j]].push_back(i);
            }
        }
        stack<int> st;
        vector<bool> vis1(V, false), vis2(V, false);
        for (int i=0; i<V; i++){
            if (!vis1[i]) dfs1(i, g, st, vis1);
        }
        int ans = 0;
        while (!st.empty()){
            int a = st.top();
            st.pop();
            if (vis2[a]) continue;
            dfs2(a, r, vis2);
            ans++;
        }
        return ans;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends