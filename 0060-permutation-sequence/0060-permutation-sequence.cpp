class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> s;
        int fac = 1; for (int i=1; i<=n; i++){
            fac *= i;
            s.push_back(i);
        }
        fac /= n;
        string ans = "";
        k--;
        while(true){
            ans += '0' + s[k / fac];
            if (ans.length() == n) break;
            s.erase(s.begin() + k/fac);
            k %= fac;
            fac /= s.size();
        }
        return ans;
    }
};