//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    int minimumNumberOfSwaps(string S){
        int st = 0;
        int ans = 0;
        int n = S.length();
        queue<int> todo;
        int mov = 0;
        for (int i=0; i<n; i++){
            if (S[i] == '['){
                if (st < 0){
                    int toSub = todo.front();
                    ans += todo.size();
                    todo.pop();
                } 
                st++;
            } 
            if (S[i] == ']'){
                if (st <= 0){
                    todo.push(i);
                }
                st--;
            }
        }
       return ans; 
    } 
}; 

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.minimumNumberOfSwaps(S) << endl;
    }
    return 0; 
} 
// } Driver Code Ends