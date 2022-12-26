class Solution {
public:
    int climbStairs(int n) {
        int prev = 1;
        int now = 1;
        for (int i=n-2; i>=0; i--){
            int tmp = now;
            now = now + prev;
            prev = tmp;
        }
        return now;
    }
};