//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int findCity(int n, int m, vector<vector<int>>& edges, int distanceThreshold){
        vector<pair<int,int>> g[n];
        for (auto it : edges){
            g[it[0]].push_back({it[1], it[2]});
            g[it[1]].push_back({it[0], it[2]});
        }
        
        int ans = -1;
        int mini = INT_MAX;
        for (int i=0; i<n; i++){
            int dist[n]; for (int j=0; j<n; j++) dist[j] = INT_MAX;
            dist[i] = 0;
            set<pair<int,int>> pq; pq.insert({0, i});
            while (!pq.empty()){
                int par = (*pq.begin()).second;
                pq.erase(pq.begin());
                for (auto it : g[par]){
                    int child = it.first;
                    int wt = it.second;
                    if (wt+dist[par] < dist[child]){
                        dist[child] = wt + dist[par];
                        pq.insert({dist[child], child});
                    }
                }
            }
            int count = 0;
            for (int j=0; j<n; j++){
                if (i == j) continue;
                if (dist[j] <= distanceThreshold) count++;
            }
            if (count <= mini){
                mini = count;
                ans = i;
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
        vector<vector<int>> adj;
        // n--;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        int dist;
        cin >> dist;
        Solution obj;
        cout << obj.findCity(n, m, adj, dist) << "\n";
    }
}

// } Driver Code Ends