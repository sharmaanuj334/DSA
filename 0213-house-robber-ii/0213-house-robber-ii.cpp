class Solution {
public:
    int sol(int start, int n, vector<int> &nums){
        int prev = 0;
        int now = nums[start];
        for (int i=start+1; i<n; i++){
            int tmp = now;
            now = max(nums[i]+prev, now);
            prev = tmp;
        }
        
        return now;
    }
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        int ans1 = sol(0, nums.size()-1, nums);
        int ans2 = sol(1, nums.size(), nums);
        return max(ans1, ans2);
    }
};