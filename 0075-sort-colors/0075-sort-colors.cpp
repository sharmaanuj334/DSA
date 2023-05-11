class Solution {
public:
    void sortColors(vector<int>& nums) {
        int a[3] = {0, 0, 0};
        for (int i : nums) a[i]++;
        for (int i=0; i<a[0]; i++) nums[i] = 0;
        for (int i=a[0]; i<a[0]+a[1]; i++) nums[i] = 1;
        for (int i=a[0]+a[1]; i<a[0]+a[1]+a[2]; i++) nums[i] = 2;
    }
};