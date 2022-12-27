class Solution {
public:
    int sol(int i, int n, vector<int> &nums, int dp[]){
        if (i >= n) return 0;
        
        if (dp[i] != -1) return dp[i];
        int pick = nums[i] + sol(i+2, n, nums, dp);
        int notPick = 0 + sol(i+1, n, nums, dp);
        
        return dp[i] = max(pick, notPick);
    }
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        int dp[nums.size()];
        memset(dp, -1, sizeof(dp));
        int ans1 = sol(0, nums.size()-1, nums, dp);
        memset(dp, -1, sizeof(dp));
        int ans2 = sol(1, nums.size(), nums, dp);
        return max(ans1, ans2);
    }
};