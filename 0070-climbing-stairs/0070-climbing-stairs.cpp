class Solution {
public: 
    int dp(int i, int n, int a[]){
        if (i == n) return 1;
        if (i > n) return 0;
        if (a[i] != -1) return a[i];
        a[i] = dp(i+1, n, a) + dp(i+2, n, a);
        return a[i];
    }
public:
    int climbStairs(int n) {
        int a[n+1];
        memset(a, -1, sizeof(a));
        return dp(0, n, a);
    }
};