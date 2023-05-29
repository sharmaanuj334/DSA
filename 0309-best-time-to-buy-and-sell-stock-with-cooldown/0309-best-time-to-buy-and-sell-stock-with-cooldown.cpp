class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size()+2, vector<int> (2, 0));
        vector<int> curr(2, 0);
        vector<int> front1(2, 0);
        vector<int> front2(2, 0);
        for (int i=prices.size()-1; i>=0; i--){
            for (int stock=1; stock>=0; stock--){
                int skip = front1[stock];
                if (stock){
                    int sell = prices[i] + front2[0];
                    curr[stock] = max(sell, skip);
                } else{
                    int buy = -prices[i] + front1[1];
                    curr[stock] = max(buy, skip);
                }
            }
            front2 = front1;
            front1 = curr;
        }
        return front1[0];
    }
};