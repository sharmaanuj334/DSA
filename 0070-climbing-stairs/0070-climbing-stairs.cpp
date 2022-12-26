class Solution {
public:
    int climbStairs(int n) {
        int a[n+1];
        a[n] = 1; a[n-1] = 1;
        for (int i=n-2; i>=0; i--){
            a[i] = a[i+1] + a[i+2];
        }
        return a[0];
    }
};