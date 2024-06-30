//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool solve(int n, int sum , vector<int> &arr, vector<vector<int>> &dp) {
        if(n == 0){
            return arr[0] == sum;
        }
         
         if(sum == 0)
           return true;
           
           if(dp[n][sum] != -1)
             return dp[n][sum]; 
          
          int take = false; 
          if(arr[n] <= sum) {
               take = solve(n-1,sum-arr[n],arr,dp);
          }

          bool not_take = solve(n-1,sum,arr,dp);
    
         return dp[n][sum] = (take || not_take);
    }
    bool isSubsetSum(vector<int>arr, int sum){
        int n = arr.size();
        
        vector<vector<int>> dp(n+1,vector<int>(sum+1,-1));
        return solve(n-1,sum,arr,dp);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends