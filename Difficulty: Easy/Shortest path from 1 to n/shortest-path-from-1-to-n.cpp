//{ Driver Code Starts
//Initial template for c++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    // int solve(int i, int n) {
    //     if(i > n)
    //       return 0;
        
    //     if(i == n){
    //         return 1;
    //     }
        
    //     int f = 1 + solve(i+1,n);
    //     int s = 1 + solve(3* i ,n);
        
    //     return min(f,s);
    // }
    int minimumStep(int n){
            if(n==1) return 0;
       if(n%3==0) {
           return 1 + minimumStep(n/3);
       }
       else {
           return 1 + minimumStep(n-1);
       }
    } 
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.minimumStep(n) << endl;
    
    }
    return 0; 
} 


// } Driver Code Ends