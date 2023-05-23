class Solution {
private:
    int lcs(string s, string t){
        int m = s.length();
        int n = t.length();
        vector<vector<int>> dp(m+1, vector<int> (n+1, 0));
        for (int i=1; i<=m; i++){
            for (int j=1; j<=n; j++){
                if (s[i-1] == t[j-1]) dp[i][j] = 1+dp[i-1][j-1];
                else dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
        return dp[m][n];
    }
public:
    int longestPalindromeSubseq(string a) {
        string s = a;
        reverse(a.begin(), a.end());
        string t = a;
        return lcs(s, t);
    }
};