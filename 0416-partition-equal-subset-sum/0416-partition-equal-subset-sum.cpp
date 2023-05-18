class Solution {
public:
    bool canPartition(vector<int>& nums){
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2) return false;
        vector<vector<bool>> dp(nums.size(), vector<bool> (sum+1, 0));
        for (int i=0; i<n; i++) dp[i][0] = 1;
        dp[0][nums[0]] = 1;
        for (int i=1; i<n; i++){
            for (int j=0; j<=sum; j++){
                if (nums[i] <= j){
                    dp[i][j] = dp[i-1][j] | dp[i-1][j-nums[i]];
                } else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[nums.size()-1][sum/2];
    }
};