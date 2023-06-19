//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int countPaths(int n, vector<vector<int>>& roads){
        vector<pair<int,int>> g[n];
        for (auto it : roads){
            g[it[0]].push_back({it[1], it[2]});
            g[it[1]].push_back({it[0], it[2]});
        }
        vector<int> ways(n, 0);
        vector<int> dist(n, INT_MAX);
        ways[0] = 1; dist[0] = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,0});
        while (!pq.empty()){
            int par = pq.top().second;
            pq.pop();
            for (auto it : g[par]){
                int child = it.first;
                int weight = it.second;
                if (dist[par]+weight > dist[child]) continue;
                if (dist[par]+weight == dist[child]){
                    ways[child] += ways[par];
                } else if (dist[par]+weight < dist[child]){
                    dist[child] = dist[par] + weight;
                    ways[child] = ways[par];
                    pq.push({dist[child], child});
                }
            }
        }
        return ways[n-1];
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;
        cout << obj.countPaths(n, adj) << "\n";
    }

    return 0;
}
// } Driver Code Ends