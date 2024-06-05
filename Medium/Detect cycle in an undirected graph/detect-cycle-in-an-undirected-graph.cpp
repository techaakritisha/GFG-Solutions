//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool solve(vector<int> adj[],int u, vector<bool> &visited) {
        queue<pair<int,int>> q;
        
        q.push({u,-1});
        visited[u] = true;
        
        while(!q.empty()) {
            pair<int,int> p = q.front();
            q.pop();
            
            int src = p.first;
            int parent = p.second;
            
            for(int &v : adj[src]) {
                if(visited[v] == false) {
                    visited[v] = true;
                    q.push({v,src});
                }
                else if(v != parent) {
                    return true;
                }
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
       vector<bool> visited(V,false);
        
        for(int i=0; i<V; i++) {
            if(!visited[i] && solve(adj,i,visited)){
                return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends