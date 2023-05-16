class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        vector<vector<int>> ans;
        for (int i=0; i<n; i++){
            int sec = intervals[i][1];
            int f = i+1;
            while (f < n && intervals[f][0] <= sec){
                sec = max(intervals[f][1], sec);
                f++;
            }
            vector<int> tmp = {intervals[i][0], sec};
            ans.push_back(tmp);
            i = f-1;
        }
        return ans;
    }
};