class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxi[n]; maxi[0] = prices[n-1];
        for (int i=n-1; i>=1; i--){
            maxi[n-i] = max(maxi[n-i-1], prices[i]);
        }
        int ans = 0;
        int buy = prices[0];
        for (int i=0; i<n; i++){
            buy = min(buy, prices[i]);
            ans = max(maxi[n-1-i]-buy, ans);
        }
        return ans;
    }
};