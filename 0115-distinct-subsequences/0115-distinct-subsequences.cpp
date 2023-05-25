class Solution {
public:
    int numDistinct(string t, string s) {
        int ls = s.length();
        int lt = t.length();
        vector<double> ans(ls+1, 0); ans[0] = 1;
        for (int i=1; i<=lt; i++){
            for (int j=ls; j>=1; j--){
                if (t[i-1] == s[j-1]){
                    ans[j] = ans[j-1] + ans[j];
                } else{
                    ans[j] = ans[j];
                }
            }
        }
        return ans[ls];
    }
};