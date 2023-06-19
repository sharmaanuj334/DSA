//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void rec(int start, vector<int> &dist, vector<int> &a){
        queue<int> q;
        q.push(start);
        while (!q.empty()){
            int par = q.front();
            q.pop();
            for (int i=0; i<a.size(); i++){
                int child = (par * a[i]) % 100000;
                if (dist[child] > dist[par]+1){
                    dist[child] = dist[par]+1;
                    q.push(child);
                }
            }
        }
    }
    int minimumMultiplications(vector<int>& arr, int start, int end){
        vector<int> dist(100000, INT_MAX);
        dist[start] = 0;
        rec(start, dist, arr);
        return (dist[end] == INT_MAX) ? -1 : dist[end];
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends