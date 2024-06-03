//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.4
    void DFS(unordered_map<int ,vector<int>> &adj,int u ,vector<bool> &visit,vector<int>&res) {
        if(visit[u] == true){
            return ;
        }
        visit[u] = true;
        res.push_back(u);
        
        for(int &v : adj[u]) {
            if(!visit[v]){
                DFS(adj,v,visit,res);
            }
        }
        
    }
    vector<int> dfsOfGraph(int V, vector<int> mp[]) {
        unordered_map<int ,vector<int>> adj;
        
        for(int i=0; i<V; i++) {
           for(auto it=mp[i].begin(); it != mp[i].end(); it++) {
               adj[i].push_back(*it);
           }
        }
        
        vector<int> res;
        vector<bool> visit(V,false);
        
         DFS(adj,0,visit,res);
         
         return res;
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
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends