//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
// User function Template for C++

/* Linked List node structure

struct Node {
    int data;
    struct Node *next;
};

*/

class Solution {
  public:
    Node* removeAllDuplicates(struct Node* head) {
      map<int,int> mp;
       
       while(head != NULL) {
           int val = head->data;
           mp[val]++;
           
           head = head->next;
       }
       
    //   vector<int> vec;
       
    //   for(auto it:mp){
    //       if(it.second == 1) {
    //           vec.push_back(it.first);
    //       }
    //   }
       
       struct Node* node = NULL;
       struct Node* curr = node;
       
       
       for(auto it=mp.begin(); it!=mp.end(); it++) {
           if(it->second == 1){
               int x = it->first;
               if(node == NULL) {
                   node = new Node(x);
                   curr = node;
               }
               else{
                   curr->next = new Node(x);
                   curr = curr->next;
               }
           }
       }
       return node;
    }
};

//{ Driver Code Starts.
/* Function to print linked list */
void printList(struct Node *head) {
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

// Driver program to test above functions
int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;

        cin >> N;

        Node *head = NULL;
        Node *temp = head;

        for (int i = 0; i < N; i++) {
            int data;
            cin >> data;
            if (head == NULL)
                head = temp = new Node(data);
            else {
                temp->next = new Node(data);
                temp = temp->next;
            }
        }

        Solution ob;
        head = ob.removeAllDuplicates(head);
        printList(head);

        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends