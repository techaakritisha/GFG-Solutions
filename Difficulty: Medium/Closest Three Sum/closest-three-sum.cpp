//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

// arr : given vector of elements
// target : given sum value

class Solution {
  public:
    int threeSumClosest(vector<int> arr, int target) {
        
sort(arr.begin(),arr.end());
        int n=arr.size();
        
        int sum=0;
        int mini=INT_MAX;
        int ans=INT_MIN;
        
        for(int i=0;i<n-2;i++){
        
           
            int l=i+1,m=n-1;
            
            while(l<m){
                sum=arr[i]+arr[l]+arr[m];
                int difference=abs(sum-target);
                
                if(difference<=mini){
                    if(difference==mini)
                        ans=max(ans,sum);
                    else ans=sum;
                    mini=difference;
                    
                }
                if(sum>target)
                    m--;
                else l++;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int key;
        cin >> key;
        // cin.ignore();
        // if (f)
        //     return 0;
        Solution ob;
        cout << ob.threeSumClosest(arr, key) << endl;
    }
    return 0;
}
// } Driver Code Ends