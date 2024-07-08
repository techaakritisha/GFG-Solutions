//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int mod = 1e9+7;
    int nthFibonacci(int n){
        int prev1 = 0;
        int prev2 = 1;
        
        int sum;
        
        for(int i=2; i<=n; i++){
            sum = (prev1 + prev2)%mod;
            prev1 = prev2;
            prev2 = sum;
        }
        return prev2;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends