class Solution {
private:
int mazeObstacles(int n, int m, vector<vector<int>> &mat){
    if (mat[0][0] == 1 || mat[n-1][m-1] == 1) return 0;
    int top[m]; top[0] = 1;
    for (int i=1; i<m; i++) top[i] = (!mat[0][i]) ? top[i-1] : 0;
    for (int i=1; i<n; i++){
        int left = (!mat[i][0]) ? top[0] : 0;
        top[0] = left;
        for (int j=1; j<m; j++){
            top[j] = (left + top[j]);
            if (mat[i][j] == 1) top[j] = 0;
            left = top[j];
        }
    }
    return top[m-1];
}
    

public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        return mazeObstacles(n, m, obstacleGrid);
    }
};