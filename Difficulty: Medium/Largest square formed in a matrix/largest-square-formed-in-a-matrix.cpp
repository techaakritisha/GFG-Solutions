//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int t[501][501];
    int solve(vector<vector<int>> &mat,int i,int j,int &maxi,vector<vector<int>> &dp) {
        if(i>=mat.size() || j>=mat[0].size())
            return 0;
          
        if(dp[i][j] != -1)
           return dp[i][j];
           
        int up = solve(mat,i+1,j,maxi,dp);
        int down = solve(mat,i,j+1,maxi,dp);
        int diag = solve(mat,i+1,j+1,maxi,dp);
        
        if(mat[i][j] == 1)
        {
           dp[i][j] = 1 + min({up,down,diag});
           maxi = max(maxi,dp[i][j]);
            return dp[i][j];
        }
        return dp[i][j] = 0;
    }
    int maxSquare(int n, int m, vector<vector<int>> mat) {
       int maxi = 0;
       
       vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
       solve(mat,0,0,maxi,dp);
      
       return maxi;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for (int i = 0; i < n * m; i++)
            cin >> mat[i / m][i % m];

        Solution ob;
        cout << ob.maxSquare(n, m, mat) << "\n";
    }
    return 0;
}
// } Driver Code Ends