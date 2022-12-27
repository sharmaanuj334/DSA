class Solution {
public:  
int sol(int m, int n, vector<vector<int>> &dp){
    if (n == 0 && m == 0) return 1;
    if (n < 0 || m < 0) return 0;
    if (dp[m][n] != -1) return dp[m][n];
    return dp[m][n] = sol(m, n-1, dp) + sol(m-1, n, dp);
}
public:
int uniquePaths(int m, int n){
    vector<vector<int>> dp(m, vector<int> (n, -1));
    return sol(m-1, n-1, dp);
}
};