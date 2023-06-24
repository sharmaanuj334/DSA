//{ Driver Code Starts
// Initial Template for C++

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
        int pa = find(a, par);
        int pb = find(b, par);
        if (pa == pb) return;
        if (size[pa] < size[pb]) swap(pa, pb);
        size[pa] += size[pb];
        par[pb] = pa;
    }
    int MaxConnection(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> par(n*n), size(n*n);
        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                par[i*n+j] = i*n+j;
                size[i*n+j] = 1;
            }
        }
        int dx[] = {1, 0, -1, 0};
        int dy[] = {0, 1, 0, -1};
        // step 1
        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                if (grid[i][j] == 1){
                    for (int f=0; f<4; f++){
                        int x = i + dx[f];
                        int y = j + dy[f];
                        if (x >= 0 && x < n && y >= 0 && y < n){
                            if (grid[x][y] == 1){
                                UnionSize(i*n+j, x*n+y, size, par);
                            }
                        }
                    }
                }
            }
        }
        int ans = 0;
        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                if (grid[i][j] == 0){
                    set<int> P;
                    for (int f=0; f<4; f++){
                        int x = i + dx[f];
                        int y = j + dy[f];
                        if (x >= 0 && x < n && y >= 0 && y < n){
                            if (grid[x][y] == 1){
                                int p = find(x*n+y, par);
                                P.insert(p);
                            }
                        }
                    }
                    int total = 1;
                    for (int p : P) total += size[p];
                    ans = max(ans, total); // one for extra i, j
                } 
            }
        }
        if (ans == 0) return n*n;
        return ans;
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }

        Solution obj;
        cout<<obj.MaxConnection(grid)<<"\n";
    }
}

// } Driver Code Ends