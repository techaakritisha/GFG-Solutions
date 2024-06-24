//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	/*
	    vector<string> result;
	    
	    void solve(int i,string temp,string s,unordered_map<string,int> &mp) {
	        if(i == s.length()) {
	            if(mp.find(temp) != mp.end()) {
	                result.push_back(temp);
	            }
	            
	            mp[temp]++;
	        }
	        
	        temp.push_back(s[i]);
	        solve(i+1,temp,s,mp);
	        temp.pop_back();
	    }
		vector<string>find_permutation(string S)
		{
          unordered_map<string,int> mp;
          string temp = "";
          solve(0,temp,S,mp);
        
         return result; 
         
         */
  
        //  2nd method
        
        
    // vector<string> result;
    // void solve(string &s , int l , int r,unordered_map<string,int> &mp) {
    //     if(l == r){
    //         if(mp.find(s) != mp.end()){
    //             result.push_back(s);
    //             return;
    //         }
    //         mp[s]++;
    //     }

    //      for(int i=l; i<=r; i++) {
    //          swap(s[l],s[r]);
    //          solve(s,l+1,r,mp);
    //          swap(s[l],s[i]);
    //      }
    // }
    // vector<string>find_permutation(string S){
       
    //   unordered_map<string,int> mp;
    //   int n = S.length();
       
    //   solve(S,0,n-1,mp);
    //   return result;    
    
    vector<string>find_permutation(string S){
        vector<string>res;

            
            sort(S.begin(), S.end());

            do
            {
                res.push_back(S);
            }while(next_permutation(S.begin(), S.end()));

            return res;
	}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    sort(ans.begin(),ans.end());
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends