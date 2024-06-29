//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    typedef pair<int,int> p;
    int spanningTree(int V, vector<vector<int>> adj[])
    {   
        vector<bool> isMST(V,false);
        priority_queue<p,vector<p>,greater<p>> pq;
        pq.push({0,0});
        
        int sum = 0;
        
        while(!pq.empty()) {
            auto p  = pq.top();
            int wt = p.first;
            int node = p.second;
            pq.pop();
            
            if(isMST[node] == true)
                continue;
                
           isMST[node]  = true;
           sum += wt;
           
           for(auto &it : adj[node]) {
               int neigh = it[0];
               int w = it[1];
               
               if(isMST[neigh] == false){
                   pq.push({w,neigh});
               }
           }
        }
        return sum;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends