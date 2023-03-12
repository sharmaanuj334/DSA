class Solution {
public:
    int row(vector<vector<int>> &a, int target){
        int n = a.size();
        int hi = n-1, lo = 0;
        while(true){
            if (hi <= lo) return lo;
            int mid = hi - (hi - lo)/2;
            if (a[mid][0] <= target){
                if (mid + 1 == n) return mid;
                else if (a[mid+1][0] > target) return mid;
                else lo = mid + 1;
            } else{
                hi = mid - 1;
            }
        }
    }
    bool exist(vector<int> &a, int target){
        int n = a.size();
        int hi = n-1, lo = 0;
        while(true){
            if (hi <= lo) return a[lo] == target;
            int mid = hi - (hi - lo)/2;
            if (a[mid] == target) return true;
            if (a[mid] < target){
                lo = mid + 1;
            } else{
                hi = mid - 1;
            }
            if (lo == n || hi == n) return false;
        }
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r = row(matrix, target);
        return exist(matrix[r], target);
    }
};