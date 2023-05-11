class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> v, h;
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                if (matrix[i][j] == 0){
                    v.push_back(i);
                    h.push_back(j);
                }
            }
        }
        for (int ele : h){
            for (int i=0; i<n; i++){
                matrix[i][ele] = 0;
            }
        }
        for (int ele : v){
            for (int j=0; j<m; j++){
                matrix[ele][j] = 0;
            }
        }
    }
};
