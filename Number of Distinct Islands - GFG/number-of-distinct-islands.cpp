//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  private:
  void dfs(int sx, int sy, int i, int j, vector<vector<bool>> &vis, vector<vector<int>> &grid, vector<pair<int,int>> &path){
      int n = grid.size();
      int m = grid[0].size();
      path.push_back({i - sx, j - sy});
      vis[i][j] = 1;
      int a[] = {1, 0, -1, 0};
      int b[] = {0, 1, 0, -1};
      for (int f=0; f<4; f++){
          int x = i + a[f];
          int y = j + b[f];
          if (x >= 0 && x < n && y >= 0 && y < m){
              if (!vis[x][y] && grid[x][y] == 1){
                  dfs(sx, sy, x, y, vis, grid, path);
              } 
          }
      }
  }
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        set<vector<pair<int,int>>> s;
        vector<vector<bool>> vis(n, vector<bool> (m, false));
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                vector<pair<int,int>> tmp;
                if (!vis[i][j] && grid[i][j] == 1){
                    dfs(i, j, i, j, vis, grid, tmp);
                    s.insert(tmp);
                } 
            }
        }
        return s.size();
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
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends