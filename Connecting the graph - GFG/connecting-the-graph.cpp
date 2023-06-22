//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int find(int a, vector<int> &par){
        if (par[a] == a) return a;
        return find(par[a], par);
    }
    void UnionSize(int a, int b, vector<int> &par, vector<int> &size){
        int par_a = find(a, par);
        int par_b = find(b, par);
        if (par_a == par_b) return;
        if (size[par_a] < par[par_b]) swap(par_a, par_b);
        par[par_b] = par_a;
        size[par_a] += size[par_b];
    }
    int Solve(int n, vector<vector<int>>& edge){
        vector<int> par(n), size(n);
        for (int i=0; i<n; i++){
            par[i] = i;
            size[i] = 1;
        }
        int extra = 0; for (auto it : edge){
            int a = it[0];
            int b = it[1];
            if (find(a, par) == find(b, par)) extra++;
            else UnionSize(a, b, par, size);
        }
        int need = 0; for (int i=0; i<n; i++) if (find(i, par) == i) need++;
        if (need-1 > extra) return -1;
        return need-1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 2; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution Obj;
        cout << Obj.Solve(n, adj) << "\n";
    }
    return 0;
}
// } Driver Code Ends