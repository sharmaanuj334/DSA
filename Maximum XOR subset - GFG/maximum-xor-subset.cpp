//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int maxXor(int a[], int n){
        int x = 0, y = 0;
        while (true){
            y = *max_element(a, a+n);
            if (!y) break;
            x = max(x, x^y);
            for (int i=0; i<n; i++) a[i] = min(a[i], a[i]^y);
        }
        return x;
	}
};

//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

	   

	    Solution ob;
	    cout << ob.maxXor(a, n) << "\n";
   
    }
    return 0;
}

// } Driver Code Ends