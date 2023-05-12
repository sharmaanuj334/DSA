class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int s = -1;
        for (int i=0; i<nums.size()-1; i++){
            if (nums[i] < nums[i+1]){
                s = i;
            }
        }
        vector<int> a;
        for (int i=s+1; i<nums.size(); i++){
            a.push_back(nums[i]);
        }
        sort(a.begin(), a.end());
        for (int i=0; i<a.size() && s >= 0; i++){
            if (nums[s] < a[i]){
                swap(nums[s], a[i]);
                break;
            } 
        } 
        sort(a.begin(), a.end());
        int f = 0;
        for (int i=0; i<nums.size(); i++){
            if (i > s) nums[i] = a[f++];
        }
    }
};