//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int find(int a, vector<int> &par){
        if (par[a] == a) return a;
        return find(par[a], par);
    }
    void Union(int a, int b, vector<int> &par){
        int pa = find(a, par);
        int pb = find(b, par);
        if (pa == pb) return;
        par[pb] = pa;
    }
    int maxRemove(vector<vector<int>>& stones, int n) {
        int maxiI = 0, maxiJ = 0;
        for (auto it : stones){
            maxiI = max(maxiI, it[0]);
            maxiJ = max(maxiJ, it[1]);
        }
        vector<int> par(maxiI+maxiJ+2);
        for (int i=0; i<maxiI+maxiJ+2; i++){
            par[i] = i;
        }
        set<int> nodes;
        for (auto it : stones){
            int row = it[0];
            int col = it[1] + maxiI + 1;
            Union(row, col, par);
            nodes.insert(row);
            nodes.insert(col);
        }
        int cnt = 0;
        for (auto it : nodes){
            if (find(it, par) == it){
                cnt++;
            }
        }
        return n - cnt;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> adj;

        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int i = 0; i < 2; ++i) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;

        cout << obj.maxRemove(adj, n) << "\n";
    }
}
// } Driver Code Ends