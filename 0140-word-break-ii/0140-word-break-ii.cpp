class Solution {

public:    

void possi(vector<string> &dictionary, string &s, vector<string> &ans, int ind, vector<string> making){
    if (ind == s.length()){
        string toAns = "";
        for (int i=0; i<making.size(); i++){
            string ele = making[i];
            toAns += ele;
            if (i<making.size()-1) toAns += " ";
        }
        ans.push_back(toAns);
    }
    for (int i=ind; i<s.length(); i++){
        string now = s.substr(ind, i-ind+1);
        if (binary_search(dictionary.begin(), dictionary.end(), now)){
            making.push_back(now);
            possi(dictionary, s, ans, i+1, making);
            making.pop_back();
        }
    }
}

public: 

vector<string> wordBreak(string &s, vector<string> &dictionary){
    sort(dictionary.begin(), dictionary.end());
    vector<string> ans;
    vector<string> making;
    possi(dictionary, s, ans, 0, making);
    return ans;
}
};