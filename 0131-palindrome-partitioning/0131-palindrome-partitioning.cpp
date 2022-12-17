class Solution {
public:
bool isPalindrome(string s){
	for (int i=0; i<s.length()/2; i++){
		if (s[i] != s[s.length()-1-i]){
			return false;
		}
	}
	return true;
}
public:
void part(int index, vector<string> v, vector<vector<string>> &ans, string s){
	if (index == s.length()){
		ans.push_back(v);
		return;
	}
	for (int i=index; i<s.length(); i++){
		string c = s.substr(index, i-index+1);
		if (isPalindrome(c)){
			v.push_back(c);
			part(i+1, v, ans, s);
			v.pop_back();
		}
	}
}
public:
vector<vector<string>> partition(string s) {
	vector<vector<string>> ans;
	int n = s.length();
	vector<string> v;
	part(0, v, ans, s);
	return ans;
}

};