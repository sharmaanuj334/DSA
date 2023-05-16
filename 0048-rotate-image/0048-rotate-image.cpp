class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i=0; i<=n/2; i++){
            for (int j=i; j<n-1-i; j++){
                int one = matrix[i][j];
                int two = matrix[j][n-1-i];
                int three = matrix[n-1-i][n-1-j];
                int four = matrix[n-1-j][i];
                matrix[j][n-1-i] = one;
                matrix[n-1-i][n-1-j] = two;
                matrix[n-1-j][i] = three;
                matrix[i][j] = four;
            }
        }
    }
};