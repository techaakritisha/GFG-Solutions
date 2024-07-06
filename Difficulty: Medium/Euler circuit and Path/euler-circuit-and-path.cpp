//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public: 
    void DFS(vector<int> adj[],int u , vector<bool> &visited) {
        visited[u] = true;
        
        for(auto it=adj[u].begin(); it!=adj[u].end(); it++) {
            int neigh = *it;
            if(visited[neigh] == false) {
                DFS(adj,neigh,visited);
            }
        }
    }
    bool isConnected(int v , vector<int> adj[]) {
        int incir = -1;
        
        for(int i=0; i<v; i++) {
            if(adj[i].size() != 0) {
                incir = i;
                break;
            }
        }
        
        vector<bool> visited(v,false);
        
        DFS(adj,incir,visited);
        
        for(int i=0; i<v; i++){
            if(visited[i] == false && adj[i].size() > 0) {
                return false;
            }
        }
        return true;
    }
	int isEulerCircuit(int V, vector<int>adj[]){
	   if(isConnected(V,adj) == false)
	      return 0;
	   
	   int degree = 0;
	   
	   for(int i=0; i<V; i++) {
	       if(adj[i].size()%2 != 0) {
	           degree++;
	       }
	   }
	   
	   if(degree > 2) 
	      return 0;
	      
	     if(degree == 2) 
	       return 1;
	       
	       return 2;
	      
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		int ans = obj.isEulerCircuit(V, adj);
		cout << ans <<"\n";	}
	return 0;
}
// } Driver Code Ends