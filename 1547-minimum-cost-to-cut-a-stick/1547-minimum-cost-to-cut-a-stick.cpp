class Solution {
private:
    int rec(int i, int j, int leftCut, int rightCut, vector<int> &cuts, vector<vector<int>> &dp){
        if (j < i) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        int mini = 1e9;
        for (int ind=i; ind<=j; ind++){
            mini = min(mini, rightCut - leftCut 
                                + rec(i, ind-1, leftCut, cuts[ind], cuts, dp) 
                                + rec(ind+1, j, cuts[ind], rightCut, cuts, dp));
        }
        return dp[i][j] = mini;
    }
public:
    int minCost(int n, vector<int>& cuts) {
        vector<vector<int>> dp(cuts.size(), vector<int> (cuts.size(), -1));
        sort(cuts.begin(), cuts.end());
        return rec(0, cuts.size()-1, 0, n, cuts, dp);
    }
};