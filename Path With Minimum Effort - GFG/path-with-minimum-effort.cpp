//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int MinimumEffort(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        priority_queue<pair<int, pair<int,int>>> pq;
        vector<vector<int>> val(n, vector<int> (m, INT_MAX)); val[0][0] = 0;
        pq.push({0, {0, 0}});
        int a[] = {1, -1, 0, 0};
        int b[] = {0, 0, 1, -1};
        while (!pq.empty()){
            int i = pq.top().second.first;
            int j = pq.top().second.second;
            pq.pop();
            for (int f=0; f<4; f++){
                int x = i + a[f];
                int y = j + b[f];
                if (x >= 0 && y >= 0 && x < n && y < m){
                    if (val[x][y] > max(abs(heights[x][y] - heights[i][j]), val[i][j])){
                        val[x][y] = max(abs(heights[x][y] - heights[i][j]), val[i][j]);
                        pq.push({-val[x][y], {x, y}});
                    }
                }
            }
        }
        return val[n-1][m-1];
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n,m; cin>>n>>m;
        vector<vector<int>> heights;
       
        for(int i=0; i<n; ++i){
            vector<int> temp;
            for(int j=0; j<m; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            heights.push_back(temp);
        }
       
        Solution obj;
        cout<<obj.MinimumEffort(heights)<<"\n";
    }
    return 0;
}
// } Driver Code Ends