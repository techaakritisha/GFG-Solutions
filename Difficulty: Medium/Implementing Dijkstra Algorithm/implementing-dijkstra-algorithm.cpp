//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S
    
    // USING MIN-HEAP
    /*
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        
        vector<int> result(V,INT_MAX);
        result[S] = 0;
        pq.push({0,S});
        
        while(!pq.empty()){
          pair<int,int> p = pq.top();
          pq.pop();
          
          
          int d = p.first;
          int node = p.second;
          
          
          for(auto &vec : adj[node]) {
              int adjnode = vec[0];
              int wt = vec[1];
              
              if(d+wt < result[adjnode]) {
                  result[adjnode] = d+wt;
                  
                  pq.push({d+wt,adjnode});
              }
          }
        }
        return result;
        
        */
        
    // USING SET
     vector <int> dijkstra(int V, vector<vector<int>> adj[], int S) {
            set<pair<int, int>> pq;

            vector<int> result(V, INT_MAX);

            result[S] = 0;
            pq.insert({0, S});

            while(!pq.empty()) {

                auto &it = *pq.begin();
                int d  = it.first;
                int node = it.second;
                pq.erase(it);

                for(auto &vec : adj[node]) {

                    int adjNode = vec[0];
                    int dist    = vec[1];

                    if(d + dist < result[adjNode]) {
                        
                        if(result[adjNode] != INT_MAX) {
                            auto iter = pq.find({result[adjNode], adjNode});
                            pq.erase(iter);
			    //OR, pq.erase({result[adjNode], adjNode});
                        }
                        
                        result[adjNode] = d + dist;
                        pq.insert({d+dist, adjNode});

                    }

                }

            }

            return result;  
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
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends