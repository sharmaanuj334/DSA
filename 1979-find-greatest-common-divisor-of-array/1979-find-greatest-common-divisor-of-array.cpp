class Solution {
public:
    int gcd(int a, int b){
        if (b == 0) return a;
        else return gcd(b, a % b);
    }
    int findGCD(vector<int>& nums) {
        int mini = nums[0];
        int maxi = nums[0];
        for (int i : nums){
            mini = min(mini, i);
            maxi = max(maxi, i);
        }
        return gcd(mini, maxi);
    }
};