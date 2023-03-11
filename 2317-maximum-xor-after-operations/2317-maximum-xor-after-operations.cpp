class Solution {
public:
    int maximumXOR(vector<int>& nums) {
        int ans = 0;
        for (int i=0; i<32; i++){
            int c = 0;
            for (int num : nums){
                if (num & (1<<i)){
                    ans += (1<<i);
                    break;
                }
            }
        }
        return ans;
    }
};