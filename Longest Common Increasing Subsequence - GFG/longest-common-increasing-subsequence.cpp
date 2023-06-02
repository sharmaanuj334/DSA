//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
    int LCIS(int arr1[], int m, int arr2[], int n){
        vector<vector<vector<int>>> dp(m+2, vector<vector<int>> (n+2, vector<int> (m+2, 0)));
        for (int i=m; i>=1; i--){
            for (int j=n; j>=1; j--){
                for (int f=i-1; f>=0; f--){
                    int notTake = max(dp[i+1][j][f], dp[i][j+1][f]);
                    int Take = 0;
                    if (arr1[i-1] == arr2[j-1] && arr1[i-1] > arr1[f-1]){
                        Take = 1 + dp[i+1][j+1][i];
                    }
                    dp[i][j][f] = max(Take, notTake);
                }
                // for f == 0
                int notTake = max(dp[i+1][j][0], dp[i][j+1][0]);
                if (arr1[i-1] == arr2[j-1]) dp[i][j][0] = max(notTake, 1 + dp[i+1][j+1][i]);
                else dp[i][j][0] = notTake;
            }
        }
        return dp[1][1][0];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int m, n;
        cin >> m;
        int arr1[m];
        for (int i = 0; i < m; i++) {
            cin >> arr1[i];
        }
        cin >> n;
        int arr2[n];
        for (int i = 0; i < n; i++) {
            cin >> arr2[i];
        }
        Solution ob;
        cout << ob.LCIS(arr1, m, arr2, n) << "\n";
    }
    return 0;
}
// } Driver Code Ends