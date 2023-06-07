//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
private:
    void bfs(int i, int j, vector<vector<int>> &image, int newColor){
        int n = image.size();
        int m = image[0].size();
        queue<pair<int,int>> q;
        q.push({i, j});
        int oldColor = image[i][j];
        image[i][j] = newColor;
        for (int z=0; z<1000000 && !q.empty(); z++){
            i = q.front().first;
            j = q.front().second;
            q.pop();
            int a[] = {1, 0, -1, 0};
            int b[] = {0, 1, 0, -1};
            for (int f=0; f<4; f++){
                int x = i + a[f];
                int y = j + b[f];
                if (x >= 0 && x < n && y >= 0 && y < m)
                    if (image[x][y] == oldColor) image[x][y] = newColor, q.push({x, y});
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor){
        int n = image.size();
        int m = image[0].size();
        bfs(sr, sc, image, newColor);
        return image;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends