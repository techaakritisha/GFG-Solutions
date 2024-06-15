//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    long long getCount(int N) {
       long dp[N + 1][10];
 
    vector<vector<int> > data
        = { { 0, 8 },          { 1, 2, 4 },
            { 1, 2, 3, 5 },    { 2, 3, 6 },
            { 1, 4, 5, 7 },    { 2, 4, 5, 6, 8 },
            { 3, 5, 6, 9 },    { 4, 7, 8 },
            { 5, 7, 8, 9, 0 }, { 6, 8, 9 } };
 
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= 9; j++) {
            if (i == 1)
                dp[i][j] = 1;
            else {
                dp[i][j] = 0;
                for (int k = 0; k < data[j].size(); k++)
                    dp[i][j] += dp[i - 1][data[j][k]];
            }
        }
    }
    long sum = 0;
    for (int j = 0; j <= 9; j++) {
        sum += dp[N][j];
    }
    return sum;
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
        cout << ob.getCount(n) << "\n";
    }
    return 0;
}

// } Driver Code Ends