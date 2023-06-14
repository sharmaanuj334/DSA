//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
         vector<pair<int,int>> adj[N];
         for (auto it : edges){
             adj[it[0]].push_back({it[1], it[2]});
         }
         vector<int> ans(N, -1);
         priority_queue<pair<int,int>> q; q.push({-0, 0}); ans[0] = 0;
         bool remain[N]; memset(remain, 0, sizeof(remain));
         while (!q.empty()){
             int par = q.top().second;
             q.pop();
             remain[par] = 0;
             for (auto it : adj[par]){
                 int child = it.first;
                 int dist = it.second;
                 if (ans[par]+dist >= ans[child] && ans[child] != -1) continue;
                 if (ans[child] == -1) ans[child] = dist + ans[par];
                 else ans[child] = min(dist+ans[par], ans[child]);
                 if (!remain[child]){
                     q.push({-ans[child], child});
                     remain[child] = 1;
                 }
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
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends