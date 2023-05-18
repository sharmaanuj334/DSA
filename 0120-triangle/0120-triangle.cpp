class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle){
        int n = triangle.size();
        vector<int> prev = {triangle[0][0]};
        for (int i=1; i<n; i++){
            vector<int> curr(i+1);
            for (int j=0; j<i+1; j++){
                int left = (j > 0) ? prev[j-1] : 1e9;
                int right = (j < i) ? prev[j] : 1e9;
                curr[j] = triangle[i][j] + min(left, right);
            }
            prev = curr;
        }
        return *min_element(prev.begin(), prev.end());
    }
};