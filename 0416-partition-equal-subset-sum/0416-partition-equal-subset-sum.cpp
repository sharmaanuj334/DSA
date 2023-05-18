class Solution {
private:
    bool rec(int sum1, int sum2, int i, vector<int> &nums, vector<vector<int>> &dp){
        if (sum1 == sum2) return true;
        if (i == nums.size()) return false;
        if (dp[i][sum1] != -1) return dp[i][sum1];
        if (nums[i] <= sum1){
            return dp[i][sum1] = rec(sum1-nums[i], sum2+nums[i], i+1, nums, dp) | rec(sum1, sum2, i+1, nums, dp);
        } 
        return dp[i][sum1] = rec(sum1, sum2, i+1, nums, dp);
    }
public:
    bool canPartition(vector<int>& nums){
        int sum = accumulate(nums.begin(), nums.end(), 0);
        vector<vector<int>> dp(nums.size(), vector<int> (sum+1, -1));
        return rec(sum, 0, 0, nums, dp);
    }
};