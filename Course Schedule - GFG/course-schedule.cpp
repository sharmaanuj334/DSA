//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    vector<int> findOrder(int n, int m, vector<vector<int>> pre) {
        vector<int> inDegree(n, 0);
        vector<int> adj[n];
        for (int i=0; i<pre.size(); i++){
            adj[pre[i][0]].push_back(pre[i][1]);
            inDegree[pre[i][1]]++;
        }
        queue<int> q;
        for (int i=0; i<n; i++) if (inDegree[i] == 0) q.push(i);
        vector<int> ans;
        while (!q.empty()){
            int par = q.front();
            ans.push_back(par);
            q.pop();
            for (int child : adj[par]){
                inDegree[child]--;
                if (inDegree[child] == 0) q.push(child);
            }
        }
        reverse(ans.begin(), ans.end());
        if (ans.size() == n) return ans;
        vector<int> empty;
        return empty;
    }
};

//{ Driver Code Starts.

int check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> prerequisites;

        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            prerequisites.push_back({u,v});
        }
        
        vector<int> adj[n];
        for (auto pre : prerequisites)
            adj[pre[1]].push_back(pre[0]);
        
        Solution obj;
        vector <int> res = obj.findOrder(n, m, prerequisites);
        if(!res.size())
            cout<<"No Ordering Possible"<<endl;
        else
            cout << check(n, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends