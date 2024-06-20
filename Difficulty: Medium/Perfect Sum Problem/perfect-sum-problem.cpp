//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int mod = 1e9+7;
	int t[1005][1005];
	int solve(int n , int sum , int arr[]) {
	    
	     if(n == 0)
	       return sum == 0;
	       
	       
	     if(t[n][sum] != -1)
	        return t[n][sum];
	        
	 
	     if(arr[n-1] > sum) {
	         return solve(n-1,sum,arr);
	     }
	      
	     int take = solve(n-1,sum-arr[n-1],arr);
	     int non_take = solve(n-1,sum,arr);
	     
	     
	     return t[n][sum] = (take + non_take)%mod;
	}
	int perfectSum(int arr[], int n, int sum)
	{
	    memset(t,-1,sizeof(t));
        return solve(n,sum,arr);
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends