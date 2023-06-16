//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        vector<pair<int,int>> g[n+1];
        for (auto it : edges){
            g[it[0]].push_back({it[1], it[2]});
            g[it[1]].push_back({it[0], it[2]});
        }
        vector<int> dist(n+1, INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        dist[1] = 1;
        pq.push({dist[1], 1});
        while (!pq.empty()){
            int par = pq.top().second;
            pq.pop();
            for (auto it : g[par]){
                int child = it.first;
                int weight = it.second;
                if (dist[child] > dist[par] + weight){
                    dist[child] = dist[par] + weight;
                    pq.push({dist[child], child});
                }
            }
        }
        vector<int> neg(1, -1);
        if (dist[n] == INT_MAX) return neg;
        // reconstructing the path
        vector<int> ans;
        int ind = n;
        ans.push_back(ind);
        while (ind != 1){
            for (auto it : g[ind]){
                int child = it.first;
                int weight = it.second;
                if (dist[child] + weight == dist[ind]){
                    ans.push_back(child);
                    ind = child;
                    break;
                }
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
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