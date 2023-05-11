class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans = {{1}};
        for (int i=1; i<numRows; i++){
            vector<int> prev = ans[i-1];
            vector<int> now = {1};
            for (int f=1; f<i; f++){
                now.push_back(prev[f-1]+prev[f]);
            }
            now.push_back(1);
            ans.push_back(now);
        }
        return ans;
    }
};