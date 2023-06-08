//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    private:
    int bfs(vector<vector<int>> &grid){
        int n = grid.size();
        int m = grid[0].size();
        int cntFresh = 0;
        queue<pair<int,int>> q;
        int t[n][m]; 
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                if (grid[i][j] == 2){
                    q.push({i, j});
                } 
                if (grid[i][j] == 1){
                    cntFresh++;
                }
                t[i][j] = 0;
            }
        }

        int a[] = {1, 0, -1, 0};
        int b[] = {0, 1, 0, -1};
        int ans = 0;
        while (!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            for (int f=0; f<4; f++){
                int x = i + a[f];
                int y = j + b[f];
                if (x >= 0 && x < n && y >= 0 && y < m){
                    if (grid[x][y] == 1){
                        grid[x][y] = 2;
                        cntFresh--;
                        t[x][y] = t[i][j] + 1;
                        q.push({x, y});
                        ans = max(t[x][y], ans);
                    } 
                }
            }
        }
        return (!cntFresh ? ans : -1);
    }
    public:
    int orangesRotting(vector<vector<int>>& grid){
        return bfs(grid);
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends