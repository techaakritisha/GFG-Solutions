//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void DFS(unordered_map<int,vector<int>> &adj, int u, vector<bool> &visited) {
        visited[u] = true;
        
        for(int &v : adj[u]){
            if(!visited[v]){
                DFS(adj,v,visited);
            }
        }
        
    }
    int numProvinces(vector<vector<int>> a, int V) {
        
        unordered_map<int,vector<int>> adj;
        
        for(int i=0; i<V; i++){
            for(int j=0; j<V; j++){
                if(a[i][j] == 1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        
        vector<bool> visited(V,false);
        int count = 0;
        
        for(int i=0; i<V; i++){
            for(int &v: adj[i]){
                if(!visited[v]){
                    count++;
                    DFS(adj,v,visited);
                }
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
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends