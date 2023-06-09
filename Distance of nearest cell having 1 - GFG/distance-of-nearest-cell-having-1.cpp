//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid){
	    int n = grid.size();
	    int m = grid[0].size();
	    queue<pair<pair<int,int>, int>> q;
	    vector<vector<int>> ans(n, vector<int> (m, 0));
	    vector<vector<bool>> vis(n, vector<bool> (m, false));
	    for (int i=0; i<n; i++){
	        for (int j=0; j<m; j++){
	            if (grid[i][j]){
	                q.push({{i, j}, 0});
	                vis[i][j] = 1;
	            } 
	        }
	    }
	    int a[] = {1, -1, 0, 0};
	    int b[] = {0, 0, 1, -1};
	    while (!q.empty()){
	        int i = q.front().first.first;
	        int j = q.front().first.second;
	        int t = q.front().second;
	        q.pop();
	        for (int f=0; f<4; f++){
	            int x = a[f] + i;
	            int y = b[f] + j;
	            if (x >= 0 && x < n && y >= 0 && y < m){
	                if (!vis[x][y]){
	                    ans[x][y] = ans[i][j] + abs(x - i) + abs(y - j);
	                    q.push({{x, y}, ans[x][y]});
	                    vis[x][y] = 1;
	                }
	            }
	        }
	    }
	    return ans;
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
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends