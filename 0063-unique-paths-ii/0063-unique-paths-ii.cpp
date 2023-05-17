class Solution {
private:
    int rec(int i, int j, int m, int n, vector<vector<int>> &a, vector<vector<int>> &dp){
        if (i >= m || j >= n) return 0;
        if (a[i][j]) return 0;
        if (i == m-1 && j == n-1) return 1;
        if (dp[i][j] != -1) return dp[i][j];
        dp[i][j] = rec(i+1, j, m, n, a, dp) + rec(i, j+1, m, n, a, dp);
        return dp[i][j];
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int> (n, -1));
        return rec(0, 0, m, n, obstacleGrid, dp);
    }
};