//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
 /* TLE
    long long largestNum(int n) {
        string s = "";
        
        for(int i=0; i<n; i++){
            s += '9';
        }
        
        int num = stoi(s);
        
        return num;
    }
    
    long long  digitSum(int num){
        if(num < 10)
          return num;
         
         int sum = 0;

        while(num > 0) {
           sum = sum + num%10;
           num = num/10;
        }
        return sum;
    }
    string findLargest(int N, int S){
        long long  large = largestNum(N);
        
        for(int i=large; i>=0; i--){
            int sum = digitSum(i);
            
            if(sum == S)
             return to_string(i);
        }
        return "-1";
        
        
        if((S==0 && N>1 ) || S>9*N) return "-1";
        string t="";
        while(S>9){
            t+='9';
            S=S-9;
        }
        t+=to_string(S);
        while(t.size()<N){
            t+='0';
        }
        if(t.size()!=N) return "-1";
        return t;
        */
    string findLargest(int N, int S){    
        
        if(N>1 && S==0 || S>9*N)
             return "-1";
             
        string t = "";
        
        while(S>9) {
            t += '9';
            S = S-9;
        }
        t += to_string(S);
        
        while(t.size() < N){
            t += '0';
        }
        
        if(t.size() != N) return "-1";
        
        return t;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, S;
        cin>>N>>S;
        
        Solution ob;
        cout<<ob.findLargest(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends