//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
class dsu{
private:
	vector<int> p, size, rank;
public:
	dsu(int n){
		p.resize(n);
		size.resize(n);
		rank.resize(n);
		for (int i=0; i<n; i++){
			p[i] = i;
			size[i] = 1;
			rank[i] = 1;
		}
	}
	int find(int u){
		if (p[u] == u) return u;
		else return p[u] = find(p[u]); // path compression, making the height of one only
    // when we need them so that in future we don't need to make recursion calls much
    // the linear line we were talking about earlier
	}
	void UnionSize(int a, int b){
		int pa = find(a);
		int pb = find(b);
		if (pa == pb) return;
		if (size[pa] < size[pb]) swap(pa, pb);
		size[pa] += size[pb];
		p[pb] = pa;
	}
};
	public:
    int spanningTree(int V, vector<vector<int>> adj[]){
        int sum = 0;
        vector<pair<int,pair<int,int>>> v;
        for (int i=0; i<V; i++){
            for (auto it : adj[i]){
                v.push_back({it[1], {i, it[0]}});
            }
        }
        sort(v.begin(), v.end());
        dsu d(V);
        for (auto it : v){
            int wt = it.first;
            int node = it.second.first;
            int adjNode = it.second.second;
            if (d.find(node) != d.find(adjNode)){
                sum += wt;
                d.UnionSize(node, adjNode);
            }
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