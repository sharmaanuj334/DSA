//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void solve(int row, int col, vector<vector<int>> &m, string s, int n, vector<vector<bool>> taken, vector<string> &ans){
	if (row == n-1 && col == n-1){
		ans.push_back(s);
		return;
	}
	if (taken[row][col]) return;
	taken[row][col] = true;
	int di[] = {+1, 0, 0, -1};
	int dj[] = {0, +1, -1, 0};
	string d = "DRLU";
	for (int i=0; i<4; i++){
	    int nextR = di[i] + row;
	    int nextC = dj[i] + col;
	    if (nextR < n && nextC < n && nextR >= 0 && nextC >= 0 && m[nextR][nextC]){
	        solve(nextR, nextC, m, s + d[i], n, taken, ans);
	    }
	}
}
public:
vector<string> findPath(vector<vector<int>> &m, int n) {
	vector<string> ans;
	vector<vector<bool>> taken(n, vector<bool> (n, false));
	string s = "";
	if (m[0][0]) solve(0, 0, m, s, n, taken, ans);
	if (ans.size()){
		return ans;
	}
	ans.push_back("-1");
	return ans;
}

};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends