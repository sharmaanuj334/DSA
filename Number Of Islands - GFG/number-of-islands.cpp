//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    pair<int,int> find(pair<int,int> a, vector<vector<pair<int,int>>> &par){
        if (par[a.first][a.second] == a) return a;
        return par[a.first][a.second] = find(par[a.first][a.second], par);
    }
    void UnionSize(pair<int,int> a, pair<int,int> b, vector<vector<int>> &size, vector<vector<pair<int,int>>> &par){
        if (size[a.first][a.second] < size[b.first][b.second]) swap(a, b);
        size[a.first][a.second] += size[b.first][b.second];
        par[b.first][b.second] = a;
    }
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators){
        vector<vector<pair<int,int>>> par(n, vector<pair<int,int>> (m));
        vector<vector<int>> size(n, vector<int> (m));
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                par[i][j] = {-1, -1};
                size[i][j] = 0;
            }
        }
        vector<int> ans; 
        int islands = 0; 
        int dx[] = {1, 0, -1, 0};
        int dy[] = {0, 1, 0, -1};
        for (auto it : operators){
            int i = it[0];
            int j = it[1];
            if (par[i][j] != make_pair(-1, -1)){
                ans.push_back(ans.back());
                continue;
            } 
            par[i][j] = {i, j};
            size[i][j] = 1;
            int c = 0; 
            for (int f=0; f<4; f++){
                int x = i + dx[f];
                int y = j + dy[f];
                if (x >= 0 && x < n && y >= 0 && y < m){
                    if (par[x][y] != make_pair(-1, -1)){
                        pair<int,int> a = find(make_pair(i, j), par);
                        pair<int,int> b = find(make_pair(x, y), par);
                        if (a == b) continue;
                        c++; islands--;
                        UnionSize(a, b, size, par);
                    }
                }
            }
            islands++; // since first islands-- is wrong since it just took the new one
            ans.push_back(islands);
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends