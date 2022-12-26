class Solution {
public:
    int fib(int n) {
        if (n == 0) return 0;
        int prev = 0;
        int fib = 1;
        for (int i=2; i<=n; i++){
            int tmp = fib;
            fib += prev;
            prev = tmp;
        }
        return fib;
    }
};