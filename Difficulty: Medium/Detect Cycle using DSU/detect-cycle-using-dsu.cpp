//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to detect cycle using DSU in an undirected graph.
	vector<int> parent;
	vector<int> rank;
	
	int find(int x) {
	    if(x ==  parent[x])
	       return x;
	       
	   return parent[x] = find(parent[x]);
	}
	
	void Union(int x, int y) {
	   int x_parent = find(x);
	   int y_parent = find(y);
	   
	   if(x_parent == y_parent)
	       return;
	       
	    if(rank[x_parent] > rank[y_parent]){
	        parent[y_parent] = x_parent;
	    }   
	    else if(rank[x_parent] < rank[y_parent]){
	        parent[x_parent] = y_parent;
	    }
	    else{
	        parent[x_parent] = y_parent;
	        rank[y_parent]++;
	    }
	}
	int detectCycle(int V, vector<int>adj[])
	{
	    parent.resize(V);
	    rank.resize(V, 0);

	    
	    for(int i=0; i<V; i++){
	        parent[i] = i;
	    }
	    
	    for(int u=0; u<V; u++){
	        for(int &v : adj[u]){
	            if(u<v) {
	                int pre_u = find(u);
	                int pre_v = find(v);
	                
	                
	                if(pre_u == pre_v)
	                    return true;
	                    
	                   Union(u,v);
	            }
	        }
	    }
	    return false;
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
		int ans = obj.detectCycle(V, adj);
		cout << ans <<"\n";	}
	return 0;
}
// } Driver Code Ends