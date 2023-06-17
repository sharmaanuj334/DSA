//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int forward(int &n, int par, vector<vector<int>> &cost, int mask, vector<vector<int>> &dp){
        if (mask == ((1<<n)-1)){
            return cost[par][0];
        }
        if (dp[par][mask] != -1) return dp[par][mask];
        int mini = INT_MAX;
        for (int i=0; i<n; i++){
            if (i == par || (mask & (1<<i))) continue;
            mini = min(mini, cost[par][i] + forward(n, i, cost, mask | (1<<i), dp));
        }
        return dp[par][mask] = mini;
    }
    int total_cost(vector<vector<int>>cost){
        int n = cost.size();
        vector<vector<int>> dp(n, vector<int> ((1<<n)+1, -1));
        return forward(n, 0, cost, 1, dp);
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>cost(n, vector<int>(n, 0));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)cin >> cost[i][j];
		Solution obj;
		int ans = obj.total_cost(cost);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends