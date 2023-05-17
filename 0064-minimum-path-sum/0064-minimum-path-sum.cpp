class Solution {
public:
    int minPathSum(vector<vector<int>> &grid){
        int m = grid.size();
        int n = grid[0].size();
        vector<int> prev(n, 0);
        for (int i=0; i<m; i++){
            vector<int> curr(n);
            for (int j=0; j<n; j++){
                if (i == 0 && j == 0){
                    curr[j] = grid[i][j];
                    continue;
                } 
                if (i-1 >= 0 && j-1 >= 0)
                    curr[j] = grid[i][j] + min(prev[j], curr[j-1]);
                else if (i-1 >= 0)
                    curr[j] = grid[i][j] + prev[j];
                else
                    curr[j] = grid[i][j] + curr[j-1];
            }
            prev = curr;
        }
        return prev[n-1];
    }
};