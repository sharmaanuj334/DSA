class Solution {
private:
    int rec(int i, bool take, vector<int> &arr, vector<vector<int>> &dp){
        if (i == arr.size()) return 0;
        if (dp[i][take] != -1) return dp[i][take];
        if (take) return dp[i][take] = max(arr[i], rec(i+1, 1, arr, dp));
        return dp[i][take] = max(-arr[i] + rec(i+1, 1, arr, dp), rec(i+1, 0, arr, dp));
    }
public:
    int maxProfit(vector<int>& arr) {
        vector<vector<int>> dp(arr.size(), vector<int> (2, -1));
        return rec(0, 0, arr, dp);
    }
};