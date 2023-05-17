class Solution {
private:
    int rec(int n, int m, vector<vector<int>> &grid, vector<vector<int>> &dp){
        if (n == 0 && m == 0) return 0;
        if (dp[n][m] != -1) return dp[n][m];
        if (n-1 >= 0 && m-1 >= 0) 
            dp[n][m] = min(rec(n-1, m, grid, dp) + grid[n-1][m], rec(n, m-1, grid, dp) + grid[n][m-1]);
        else if (n-1 >= 0)
            dp[n][m] = rec(n-1, m, grid, dp) + grid[n-1][m];
        else
            dp[n][m] = rec(n, m-1, grid, dp) + grid[n][m-1];
        return dp[n][m];
    }
public:
    int minPathSum(vector<vector<int>> &grid){
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int> (n, -1));
        return grid[m-1][n-1]+rec(m-1, n-1, grid, dp);
    }
};