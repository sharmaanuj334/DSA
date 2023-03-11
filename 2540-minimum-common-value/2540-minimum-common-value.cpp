class Solution {
public:
    bool binary_search(vector<int> &a, int num){
	int n = a.size();
	int hi = n-1, lo = 0;
	while(true){
		if (hi < lo) return false;
		int mid = hi - (hi-lo)/2;
		if (a[mid] == num) return true;
		else if (a[mid] < num){
			lo = mid+1;
		} else{
			hi = mid-1;
		}
	}
        return false;
}
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        for (int i : nums1){
            if (binary_search(nums2, i)){
                return i;
            }
        }
        return -1;
    }
};