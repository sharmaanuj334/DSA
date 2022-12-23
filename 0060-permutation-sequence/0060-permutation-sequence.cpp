class Solution {
public: 
    void pos(string &ans, set<int> &taken, int k, int n, int fac, int cases){
        for (int ind=1; ind<=n; ind++){
            if (taken.count(ind)) continue;
            cases += fac;
            if (k <= cases){
                ans += ind + '0';
                cases -= fac;
                if (ans.length() == n) return;
                fac /= n - ans.length();
                taken.insert(ind);
                pos(ans, taken, k, n, fac, cases);
                break;
            }
        }
    }
public:
    string getPermutation(int n, int k) {
        set<int> taken;
        string ans = "";
        int fac = 1; for (int i=1; i<n; i++) fac *= i;
        pos(ans, taken, k, n, fac, 0);
        return ans;
    }
};