class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle){
        int n = triangle.size();
        int dp[n][n]; dp[0][0] = triangle[0][0];
        for (int i=1; i<n; i++){
            for (int j=0; j<i+1; j++){
                int left = (j > 0) ? dp[i-1][j-1] : 1e9;
                int right = (j < i) ? dp[i-1][j] : 1e9;
                dp[i][j] = triangle[i][j] + min(left, right);
            }
        }
        int mini = 1e9;
        for (int i=0; i<n; i++) mini = min(mini, dp[n-1][i]);
        return mini;
    }
};