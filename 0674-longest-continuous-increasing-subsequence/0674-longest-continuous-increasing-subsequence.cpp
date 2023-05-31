class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n = nums.size();
        int c = 1, ans = 1;
        for (int i=1; i<n; i++){
            if (nums[i-1] < nums[i]) c++;
            else{
                ans = max(ans, c);
                c = 1;
            }
        }
        return max(ans, c);
    }
};