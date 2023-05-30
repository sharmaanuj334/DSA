class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int hash[n], len[n];
        for (int i=0; i<n; i++){
            hash[i] = i;
            len[i] = 1;
        }
        int maxi = 1;
        int Index = 0;
        for (int i=0; i<n; i++){
            for (int j=0; j<i; j++){
                if (arr[i] % arr[j] == 0){
                    if (len[j]+1 >= len[i]){
                        len[i] = len[j]+1;
                        hash[i] = j;
                    }
                }
            }
            if (len[i] > maxi){
                Index = i;
                maxi = len[i];
            }
        }
        vector<int> lis = {arr[Index]};
        while (hash[Index] != Index){
            Index = hash[Index];
            lis.push_back(arr[Index]);
        }
        reverse(lis.begin(), lis.end());
        return lis;
    }
};