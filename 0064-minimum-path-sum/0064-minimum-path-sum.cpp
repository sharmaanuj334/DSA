class Solution {
public:
    int minPathSum(vector<vector<int>> &grid){
        int dp[grid[0].size()]; dp[0] = grid[0][0];
        for (int i=1; i<grid[0].size(); i++){
            dp[i] = dp[i-1] + grid[0][i];
        }
        for (int i=1; i<grid.size(); i++){
            int left = 0;
            for (int j=0; j<grid[0].size(); j++){
            if (!j) dp[j] = dp[j] + grid[i][j] + left;
            else dp[j] = min(dp[j], left) + grid[i][j];
            left = dp[j];
            }
        }
        return dp[grid[0].size()-1];
    }
};