//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    void bfs(priority_queue<pair<int,int>> &q, vector<int> &t, vector<int> g[], bool vis[]){
        while (!q.empty()){
            int par = q.top().second;
            q.pop();
            vis[par] = 0;
            for (int child : g[par]){
                if (t[par]+1 < t[child]){
                    t[child] = t[par] + 1;
                    if (!vis[child]) q.push({-t[child], child}), vis[par] = 1;
                }
            }
        }
    }
    int diff(string &s1, string &s2){
        int diff = 0; for (int i=0; i<s1.length(); i++){
            if (s1[i] != s2[i]) diff++;
        }
        return diff;
    }
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList){
        int n = wordList.size();
        vector<int> g[wordList.size()];
        int tar = -1;
        priority_queue<pair<int,int>> q;
        vector<int> t(n, INT_MAX);
        bool vis[n]; memset(vis, 0, sizeof(vis));
        for (int i=0; i<wordList.size(); i++){
            if (wordList[i] == targetWord) tar = i;
            if (wordList[i] == startWord) q.push({-1, i}), vis[i] = true, t[i] = 1;
            if (diff(wordList[i], startWord) == 1) q.push({-2, i}), vis[i] = true, t[i] = 2;
            for (int j=i+1; j<wordList.size(); j++){
                if (diff(wordList[i], wordList[j]) <= 1){
                    g[i].push_back(j);
                    g[j].push_back(i);
                }
            }
        }
        if (q.empty() || tar == -1) return 0;
        bfs(q, t, g, vis);
        if (t[tar] == INT_MAX) return 0;
        return t[tar];
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends