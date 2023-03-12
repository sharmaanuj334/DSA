class Solution {
public:
    bool isValid(vector<int> &weights, int days, int capacity){
        int sum = 0;
        int day = 1;
        for (int num : weights){
            if (sum + num <= capacity) sum += num;
            else{
                sum = num;
                day++;
            }
        }
        return (day <= days);
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int sum = 0, maxi = 0;
        for (int num : weights){
            sum += num;
            maxi = max(maxi, num);
        } 
        int lo = maxi, hi = sum;
        while(true){
            if (hi <= lo) return lo;
            int mid = hi - (hi - lo)/2;
            bool valid = isValid(weights, days, mid);
            if (valid && !isValid(weights, days, mid-1)) return mid;
            else if (valid){
                hi = mid - 1;
            } else{
                lo = mid + 1;
            }
        }
    }
};