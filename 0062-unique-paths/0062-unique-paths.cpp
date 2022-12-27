class Solution {
public:
    int uniquePaths(int m, int n){
        long long int upFac = 1;
        for (int i=min(n, m); i<=m+n-2; i++){
            upFac *= i;
            if (i <= n+m-1) upFac /= (i-(min(n, m)-1));
        }
        return upFac;
    }
};