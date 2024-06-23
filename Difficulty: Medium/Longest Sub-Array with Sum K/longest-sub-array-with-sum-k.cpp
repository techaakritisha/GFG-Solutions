//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
  
    int lenOfLongSubarr(int A[],  int n, int k) 
    { 
             unordered_map<int,int>mp;
        int ans=0;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=A[i];


            if(sum==k){
                ans=max(ans,i+1);
            }
            int rem=sum-k;


            if(mp.find(rem)!=mp.end()){
                ans=max(ans,i-mp[rem]);
            }


            if(mp.find(sum)==mp.end()){
              
                mp[sum]=i;
            }
        }
        return ans;

    } 
};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends