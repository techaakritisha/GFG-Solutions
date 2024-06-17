//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int rectanglesInCircle(int r) {
        int count = 0;
        
        if(r == 1)
          return 1;
         
        int d = 2*r;
        int area = d * d;
        
        for(int i=1; i<=d; i++){
            for(int j=1; j<=d; j++){
                int curr = i*i + j*j;
                
                if(curr <= area)
                  count++;
            }
        }
       return count;
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
        int ans = ob.rectanglesInCircle(n);
        cout << ans << "\n";
    }
}
// } Driver Code Ends