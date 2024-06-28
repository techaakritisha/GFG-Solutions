//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool palindrome_checker(string s){
        string copy=s;
        reverse(s.begin(), s.end());
        return (s==copy);
    }
    string pattern(vector<vector<int>> &arr) {
       int n=arr.size(),m=arr[0].size();
        
        for(int j=0;j<n;j++){
        string s="";
            for(int i=0;i<m;i++){
                s+=arr[j][i]+'0';
            }
        if(palindrome_checker(s))
            return  (to_string(j)) +" R" ;
        }
        for(int j=0;j<m;j++){
        string s="";
            for(int i=0;i<n;i++){
                s+=arr[i][j]+'0';
            }
        if(palindrome_checker(s))
            return  (to_string(j) )+" C" ;
        }
        return "-1";
    }
};


//{ Driver Code Starts.

int main() {

    int t, n, i, j, flag, k;
    cin >> t;

    while (t--) {
        cin >> n;
        vector<vector<int>> a(n, vector<int>(n));

        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++)
                cin >> a[i][j];
        }
        Solution ob;
        cout << ob.pattern(a) << endl;
    }
    return 0;
}
// } Driver Code Ends