class Solution {
public:
    int findNumberOfLIS(vector<int>& arr) {
        int n = arr.size();
        vector<int> cnt(n, 1), len(n, 1); 
        int maxi = 1;
        for (int i=0; i<n; i++){
            for (int j=0; j<i; j++){
                if (arr[i] > arr[j] && len[j]+1 > len[i]){
                    len[i] = len[j]+1;
                    // inherited
                    cnt[i] = cnt[j];
                }
                else if (arr[i] > arr[j] && len[j]+1 == len[i]){
                    // can use this as replacement
                    cnt[i] += cnt[j];
                }
            }
            maxi = max(maxi, len[i]);
        }
        int ans = 0;
        for (int i=0; i<n; i++) ans += (maxi == len[i]) * cnt[i];
        return ans;
    }
};