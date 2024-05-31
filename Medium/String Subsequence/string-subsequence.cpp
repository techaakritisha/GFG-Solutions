//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  int t[501][501];
  int mod = 1e9+7;
    int solve(int m, int n, string &s1 , string &s2) {
      if((m == 0 && n == 0 ) || n == 0) 
          return 1;
          
        if(m == 0) 
          return 0;
          
         if(t[m][n] != -1) 
            return t[m][n];
            
         if(s1[m-1] == s2[n-1]) 
          return t[m][n] = ((solve(m-1,n-1,s1,s2))%mod + (solve(m-1,n,s1,s2))%mod) % mod;
         
         return t[m][n] = (solve(m-1,n,s1,s2))%mod;
    }
    int countWays(string s1, string s2) {
        int m = s1.length();
        int n = s2.length();
        
        memset(t,-1,sizeof(t));
        
        return solve(m,n,s1,s2);
    }
      
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        string s1;
        getline(cin, s1);

        string s2;
        getline(cin, s2);

        Solution obj;
        int res = obj.countWays(s1, s2);

        cout << res << endl;
    }
}

// } Driver Code Ends