class Solution {
public:
int minimumTotal(vector<vector<int>>& triangle){
    int n = triangle.size();
	int m = triangle[n-1].size(); 
	int dp[m]; for (int i=0; i<m; i++) dp[i] = 1e9; 
	dp[0] = triangle[0][0];
	int mini = triangle[0][0];
	for (int i=1; i<triangle.size(); i++){
		int left = 1e9; mini = 1e9;
		for (int j=0; j<triangle[i].size(); j++){
			int tmp = dp[j];
			dp[j] = min(dp[j], left) + triangle[i][j];
			left = tmp;
			mini = min(mini, dp[j]);
		} 
	}
	return mini;
}
};