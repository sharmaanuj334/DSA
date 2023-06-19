//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int minimumCost(vector<vector<int>>& flights, int n, int k) {
        vector<pair<int,int>> g[n];
        for (auto it : flights){
            g[it[0]-1].push_back({it[1]-1, it[2]});
        }
        vector<int> dist(n, INT_MAX); dist[k-1] = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, k-1});
        while (!pq.empty()){
            int par = pq.top().second;
            pq.pop();
            for (auto it : g[par]){
                int child = it.first;
                int weight = it.second;
                if (dist[par]+weight < dist[child]){
                    dist[child] = dist[par] + weight;
                    pq.push({dist[child], child});
                }
            }
        }
        int budget = *max_element(dist.begin(), dist.end());
        if (budget == INT_MAX) return -1;
        return budget;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int size;
        cin >> size;
        vector<vector<int>> flights(size,vector<int>(3));
        for (int i = 0; i < size; i++) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            flights[i]=temp;
        }

        Solution ob;
        cout << ob.minimumCost(flights, n, k) << "\n";
    }
}

// } Driver Code Ends