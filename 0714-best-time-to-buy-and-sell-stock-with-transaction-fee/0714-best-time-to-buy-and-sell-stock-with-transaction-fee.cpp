class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int> (2, 0));
        for (int i=n-1; i>=0; i--){
            for (int j=1; j>=0; j--){
                int skip = dp[i+1][j];
                if (j){
                    int sell = prices[i] - fee + dp[i+1][0];
                    dp[i][j] = max(sell, skip);
                } else{
                    int buy = -prices[i] + dp[i+1][1];
                    dp[i][j] = max(buy, skip);
                }
            }
        }
        return dp[0][0];
    }
};