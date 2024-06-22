//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int mod = 1e9+7;
	int building = 1;
	int space = 0;
	int t[100001][2];
	int solve(int n , int status) {
	    if(n == 0)
	       return 1;
	   
	    if(t[n][status] != -1)
	        return t[n][status];
	    
	    if(status == building){
	        return t[n][status] = (solve(n-1,space))%mod;
	    }
	    else{
	        return t[n][status] = ((solve(n-1,building))%mod + (solve(n-1,space)%mod))%mod;
	    }
	}
	int TotalWays(int N)
	{   
	    memset(t,-1,sizeof(t));
	    long long  x = ((solve(N-1,building))%mod + (solve(N-1,space))%mod)%mod;
	    return (x*x)%mod;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution ob;
		int ans = ob.TotalWays(N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends