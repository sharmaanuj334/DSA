class Solution {
public:  
int sol(int m, int n, vector<vector<int>> &dp){
    if (n == 0 && m == 0) return 1;
    if (n < 0 || m < 0) return 0;
    int left = 0, top = 0;
    if (n >= 1){
        dp[m][n-1] = (dp[m][n-1] != -1) ? dp[m][n-1] : sol(m, n-1, dp);
        left = dp[m][n-1];
    }
    if (m >= 1){
        dp[m-1][n] = (dp[m-1][n] != -1) ? dp[m-1][n] : sol(m-1, n, dp);
        top = dp[m-1][n];
    }
    return left+top;
}
public:
int uniquePaths(int m, int n){
    vector<vector<int>> dp(m, vector<int> (n, -1));
    return sol(m-1, n-1, dp);
}
};