//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  private:
    void dfs(int i, int j, vector<vector<bool>> &vis, vector<vector<int>> &grid){
        vis[i][j] = 1;
        int a[] = {1, 0, -1, 0};
        int b[] = {0, 1, 0, -1};
        int n = grid.size();
        int m = grid[0].size();
        for (int f=0; f<4; f++){
            int x = i + a[f];
            int y = j + b[f];
            if (x >= 0 && x < n && y >= 0 && y < m){
                if (!vis[x][y] && grid[x][y] == 1) dfs(x, y, vis, grid);
            }
        }
    }
  public:
    int numberOfEnclaves(vector<vector<int>> &grid){
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool> (m, false));
        for (int i=0; i<n; i++){
            if (!vis[i][0] && grid[i][0] == 1) dfs(i, 0, vis, grid);
            if (!vis[i][m-1] && grid[i][m-1] == 1) dfs(i, m-1, vis, grid);
        }
        for (int j=0; j<m; j++){
            if (!vis[0][j] && grid[0][j] == 1) dfs(0, j, vis, grid);
            if (!vis[n-1][j] && grid[n-1][j] == 1) dfs(n-1, j, vis, grid);
        }
        int ans = 0; for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                if (grid[i][j] == 1 && !vis[i][j]) ans++;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends