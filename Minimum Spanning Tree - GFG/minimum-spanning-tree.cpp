//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int find(int a, vector<int> &par){
	    if (par[a] == a) return a;
	    return par[a] = find(par[a], par);
	}
	void UnionSize(int a, int b, vector<int> &size, vector<int> &par){
	    int par_a = find(a, par);
	    int par_b = find(b, par);
	    if (par_a == par_b) return;
	    if (size[par_a] < size[par_b]) swap(par_a, par_b);
	    par[par_b] = par_a;
	}
    int spanningTree(int V, vector<vector<int>> adj[]){
        vector<pair<int, pair<int,int>>> edges;
        for (int i=0; i<V; i++){
            for (auto it : adj[i]){
                int a = i;
                int b = it[0];
                int wt = it[1];
                edges.push_back({wt, {a, b}});
            }
        }
        sort(edges.begin(), edges.end());
        vector<int> par(V), size(V);
        for (int i=0; i<V; i++){
            par[i] = i;
            size[i] = 1;
        }
        int sum = 0; for (auto it : edges){
            int wt = it.first;
            int a = it.second.first;
            int b = it.second.second;
            if (find(a, par) == find(b, par)) continue;
            sum += wt;
            UnionSize(a, b, size, par);
        }
        return sum;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends