class Solution {
public:
    int uniquePaths(int m, int n) {
        int top[n]; 
        for (int i=0; i<n; i++) top[i] = 1;
        for (int i=1; i<m; i++){
            int left = 1;
            for (int j=1; j<n; j++){
                int now = top[j] + left;
                left = now;
                top[j] = now;
            }
        }
        return top[n-1];
    }
};