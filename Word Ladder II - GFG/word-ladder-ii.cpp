//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    vector<vector<string>>findSequences(string beginWord, string endWord, vector<string>& wordList) {
        set<string> s(wordList.begin(), wordList.end());
        queue<vector<string>> q;
        q.push({beginWord});
        vector<string> toDel = {beginWord};
        int oldLevel = 0;
        vector<vector<string>> ans;
        while (!q.empty()){
            vector<string> temp = q.front();
            q.pop();
            int level = temp.size();
            if (level != oldLevel){
                for (auto it : toDel){
                    s.erase(it);
                }
                toDel.clear();
            }
            string word = temp.back();
            if (word == endWord) ans.push_back(temp);
            else{
                string copy = word;
                for (int i=0; i<copy.size(); i++){
                    for (char c='a'; c<='z'; c++){
                        copy[i] = c;
                        if (s.count(copy)){
                            temp.push_back(copy);
                            q.push(temp);
                            toDel.push_back(copy);
                            temp.pop_back();
                        }
                    }
                    copy = word;
                }
            }
            oldLevel = level;
        }
        return ans;
    }
};

//{ Driver Code Starts.

bool comp(vector<string> a, vector<string> b)
{
    string x = "", y = "";
    for(string i: a)
        x += i;
    for(string i: b)
        y += i;
    
    return x<y;
}

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
		vector<vector<string>> ans = obj.findSequences(startWord, targetWord, wordList);
		if(ans.size()==0)
		    cout<<-1<<endl;
		else
		{
		    sort(ans.begin(), ans.end(), comp);
            for(int i=0; i<ans.size(); i++)
            {
                for(int j=0; j<ans[i].size(); j++)
                {
                    cout<<ans[i][j]<<" ";
                }
                cout<<endl;
            }
		}
	}
	return 0;
}
// } Driver Code Ends