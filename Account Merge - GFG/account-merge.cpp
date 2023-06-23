//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
    int find(int a, vector<int> &par){
        if (par[a] == a) return a;
        return find(par[a], par);
    }
    void UnionSize(int a, int b, vector<int> &par, vector<int> &size){
        int par_a = find(a, par);
        int par_b = find(b, par);
        if (par_a == par_b) return;
        if (size[par_a] < size[par_b]) swap(par_a, par_b);
        par[par_b] = par_a;
        size[par_a] += size[par_b];
    }
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts){
        int n = accounts.size();
        map<string,int> m;
        vector<int> par(n), size(n);
        for (int i=0; i<n; i++){
            par[i] = i;
            size[i] = 1;
        }
        for (int i=0; i<n; i++){
            for (int j=1; j<accounts[i].size(); j++){
                if (m[accounts[i][j]] != 0){ // someone already has this one
                    UnionSize(i, m[accounts[i][j]]-1, par, size);
                } else{
                    m[accounts[i][j]] = i+1;
                }
            }
        }
        vector<string> tmp[n];
        for (auto it : m){
            string s = it.first;
            int node = find(it.second-1, par);
            tmp[node].push_back(s);
        }
        vector<vector<string>> ans;
        for (int i=0; i<n; i++){
            if (tmp[i].size() == 0) continue;
            sort(tmp[i].begin(), tmp[i].end());
            tmp[i].insert(tmp[i].begin(), accounts[i][0]);
            ans.push_back(tmp[i]);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    vector<vector<string>> accounts;

    for (int i = 0; i < n; i++)
    {
      vector<string> temp;
      int x;
      cin >> x;

      for (int j = 0; j < x; j++)
      {
        string s1;
        cin >> s1;
        temp.push_back(s1);
      }
      accounts.push_back(temp);
    }

    Solution obj;
    vector<vector<string>> res = obj.accountsMerge(accounts);
    sort(res.begin(), res.end());
    cout << "[";
    for (int i = 0; i < res.size(); ++i)
    {
      cout << "[";
      for (int j = 0; j < res[i].size(); j++)
      {
        if (j != res[i].size() - 1)
          cout << res[i][j] << ","
               << " ";
        else
          cout << res[i][j];
      }
      if (i != res.size() - 1)
        cout << "], " << endl;
      else
        cout << "]";
    }
    cout << "]"
         << endl;
  }
}
// } Driver Code Ends