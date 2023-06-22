//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
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
        size[par_a] += size[par_b];
    }
    int numProvinces(vector<vector<int>> adj, int V) {
        vector<int> par(V), size(V);
        for (int i=0; i<V; i++){
            par[i] = i;
            size[i] = 1;
        }
        for (int i=0; i<adj.size(); i++){
            for (int j=0; j<adj[i].size(); j++){
                if (adj[i][j]){
                    UnionSize(i, j, size, par);
                }
            }
        }
        int c = 0; for (int i=0; i<V; i++) if (find(i, par) == i) c++;
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