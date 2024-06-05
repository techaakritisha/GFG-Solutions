//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool solve(vector<int> adj[] , int u, vector<bool> &visited , vector<bool> &current) {
        visited[u] = true;
        current[u] = true;
        
        for(int &v : adj[u]) {
           if(visited[v] == false && solve(adj,v,visited,current)){
               return true;
           }    
           else if(current[v] == true){
                return true;
           }
        }
        
        current[u] = false;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        vector<bool> visited(V,false);
        vector<bool> current(V,false);
        
        for(int i=0; i<V; i++){
            if(!visited[i] && solve(adj,i,visited,current)){
                return true;
            }
        }
        return false;
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