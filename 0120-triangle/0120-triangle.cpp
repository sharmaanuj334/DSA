class Solution {
private:
    int rec(int i, int j, vector<vector<int>> &t, vector<vector<int>> &dp){
        if (i == t.size()-1) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        dp[i][j] = min(t[i+1][j]+rec(i+1, j, t, dp), t[i+1][j+1]+rec(i+1, j+1, t, dp));
        return dp[i][j];
    }
public:
    int minimumTotal(vector<vector<int>>& triangle){
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int> (n, -1));
        return triangle[0][0]+rec(0, 0, triangle, dp);
    }
};