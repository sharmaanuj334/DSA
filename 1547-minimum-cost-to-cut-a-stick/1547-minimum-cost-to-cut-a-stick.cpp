class Solution {
public:
    int minCost(int n, vector<int>& cuts){
        sort(cuts.begin(), cuts.end());
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);
        vector<vector<int>> dp(cuts.size()+2, vector<int> (cuts.size()+2, 0));
        for (int i=cuts.size()-2; i>=1; i--){
            for (int j=i; j<=cuts.size()-2; j++){
                int mini = 1e9;
                for (int ind = i; ind <= j; ind++){
                    mini = min(mini, cuts[j+1] - cuts[i-1] + dp[i][ind-1] + dp[ind+1][j]);
                }
                dp[i][j] = mini;
            }
        }
        return dp[1][cuts.size()-2];
    }
};