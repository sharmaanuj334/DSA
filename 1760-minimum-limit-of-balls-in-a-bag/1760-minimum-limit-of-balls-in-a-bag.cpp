class Solution {
public:
    int operations(vector<int> &a, int ans){
        int opr = 0;
        for (int num : a){
            if (num > ans) opr += num / ans - (num % ans == 0);
        }
        return opr;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int n = nums.size();
        int hi = *max_element(nums.begin(), nums.end());
        int lo = 1;
        while(true){
            if (hi <= lo) return lo;
            int mid = hi - (hi - lo) / 2;
            int opr = operations(nums, mid);
            int oprPrev = operations(nums, mid-1);
            if (opr <= maxOperations && oprPrev > maxOperations) return mid;
            else if (opr <= maxOperations){
                hi = mid - 1;
            } else{
                lo = mid + 1;
            }
        }
    }
};