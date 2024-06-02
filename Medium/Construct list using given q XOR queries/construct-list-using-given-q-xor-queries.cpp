//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Matrix {
  public:
    template <class T>
    static void input(vector<vector<T>> &A, int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d ", &A[i][j]);
            }
        }
    }

    template <class T>
    static void print(vector<vector<T>> &A) {
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[i].size(); j++) {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
  
  /*
  
    1110/1115 😔  :)
    
    void getxor(vector<int> &v , int val) {
        for(int i=0; i<v.size(); i++) {
            v[i] = v[i]^val;
        }

    }
    vector<int> constructList(int q, vector<vector<int>> &queries) {
         vector<int> res;
         res.push_back(0);
         
         for(int i=q-1; i>=0; i--) {
             if(queries[i][0] == 0) {
                 res.push_back(queries[i][1]);
             }
             else{
                 getxor(res,queries[i][1]);
             }
         }
         
         sort(begin(res),end(res));
         return res;
         
         
         */
         
    vector<int> constructList(int q, vector<vector<int>> &queries) {
            
        int var = 0;
        
        vector<int> res;
        
        for(int i=q-1; i>=0; i--) {
            if(queries[i][0] == 1){
                var ^= queries[i][1];
            } 
            else{
                res.push_back(var^queries[i][1]);
            }
        }
        
        res.push_back(var^0);
        
        sort(begin(res),end(res));
        
        return res;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int q;
        scanf("%d", &q);

        vector<vector<int>> queries(q, vector<int>(2));
        Matrix::input(queries, q, 2);

        Solution obj;
        vector<int> res = obj.constructList(q, queries);

        Array::print(res);
    }
}

// } Driver Code Ends