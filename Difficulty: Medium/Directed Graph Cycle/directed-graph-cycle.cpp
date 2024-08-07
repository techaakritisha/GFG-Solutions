//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  /*
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> deg(V,0);
        queue<int> q;
        
        for(int i=0; i<V; i++){
            for(int &v : adj[i]){
                deg[v]++;
            }
        }
        
        int count = 0;
        
        for(int i=0; i<V; i++){
            if(deg[i] == 0){
                q.push(i);
                count++;
            }
        }
        
        while(!q.empty()){
            int u = q.front();
            q.pop();
            
            for(int &v : adj[u]){
                deg[v]--;
                
                if(deg[v] == 0) {
                    q.push(v);
                    count++;
                }
            }
        }
        
        if(count == V)
           return false;
        
        
          return true;
    }
    */
    bool isCyclic(int V, vector<int> adj[]) {
       vector<int> degree(V,0);
       queue<int> q;
       
       
       for(int i=0; i<V; i++) {
           for(int &v:adj[i]){
               degree[v]++;
           }
       }
       
       int count = 0;
       
       for(int i=0; i<V; i++){
           if(degree[i] == 0){
               q.push(i);
               count++;
           }
       }
       
       
       while(!q.empty()){
           int f = q.front();
           q.pop();
           
           for(int &v : adj[f]){
               degree[v]--;
               if(degree[v] == 0) {
                   q.push(v);
                   count++;
               }
           }
       }
       
       if(count == V) {
           return false;
       }
       return true;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends