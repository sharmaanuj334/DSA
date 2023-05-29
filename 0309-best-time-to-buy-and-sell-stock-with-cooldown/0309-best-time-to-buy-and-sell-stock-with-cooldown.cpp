class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size()+2, vector<int> (2, 0));
        for (int i=prices.size()-1; i>=0; i--){
            for (int stock=1; stock>=0; stock--){
                int skip = dp[i+1][stock];
                if (stock){
                    int sell = prices[i] + dp[i+2][0];
                    dp[i][stock] = max(sell, skip);
                } else{
                    int buy = -prices[i] + dp[i+1][1];
                    dp[i][stock] = max(buy, skip);
                }
            }
        }
        return dp[0][0];
    }
};