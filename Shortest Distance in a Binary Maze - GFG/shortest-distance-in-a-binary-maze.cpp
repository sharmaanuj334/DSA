//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source, 
                        pair<int, int> end) {
        queue<pair<pair<int,int>, int>> q;
        q.push({source, 0});
        int n = grid.size();
        int m = grid[0].size();
        bool vis[n][m]; memset(vis, 0, sizeof(vis));
        while (!q.empty()){
            int i = q.front().first.first;
            int j = q.front().first.second;
            int p = q.front().second;
            pair<int,int> here = {i, j};
            if (here == end) return p;
            q.pop();
            int a[] = {1, -1, 0, 0};
            int b[] = {0, 0, 1, -1};
            for (int f=0; f<4; f++){
                int x = i + a[f];
                int y = j + b[f];
                if (x >= 0 && y >= 0 && x < n && y < m){
                    if (grid[x][y] && !vis[x][y]){
                        q.push({{x, y}, p+1});
                        vis[x][y] = 1;
                    }
                }
            }
        }
        return -1;
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

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends