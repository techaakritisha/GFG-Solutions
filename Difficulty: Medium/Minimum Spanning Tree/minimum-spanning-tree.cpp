//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    /*
    
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
        
        */
    vector<int> rank;
    vector<int> parent;
    
    void Union(int x , int y) {
        int parent_x = find(x);
        int parent_y = find(y);
        
        if(parent_x == parent_y)
             return;
             
        if(rank[parent_x] > rank[parent_y]) {
            parent[parent_y] = parent_x;
        }
        else if(rank[parent_y] > rank[parent_x]){
            parent[parent_x] = parent_y;
        }
        else{
            parent[parent_x] = parent_y; 
            rank[parent_y]++;
        }
    }
    int find(int x){
        if(x == parent[x])
         return x;
         
        return parent[x] = find(parent[x]);
    }
    int KruskalAlgorithm(vector<vector<int>> &vec) {
        int sum = 0;
        for(auto &it : vec){
            int u = it[0];
            int v = it[1];
            int wt= it[2];
            
           int parent_u = find(u);
           int parent_v = find(v);
           
           if(parent_u != parent_v){
               Union(u,v);
               sum += wt;
           }
        }
        return sum;
    }
    int spanningTree(int V, vector<vector<int>> adj[]){
          
          vector<vector<int>> vec;
          
          parent.resize(V);
          rank.resize(V,0);
          
          for(int i=0; i<V; i++){
              parent[i] = i;
          }
          
          for(int i=0; i<V; i++) {
              for(auto &temp : adj[i]) {
                  int u = temp[0];
                  int wt = temp[1];
                  
                  vec.push_back({i,u,wt});
              }
          }
          
          auto comparator=[&](vector<int> &a , vector<int> &b) {
              return a[2] < b[2];
          };
          
          sort(begin(vec),end(vec),comparator);
          
          return KruskalAlgorithm(vec);
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