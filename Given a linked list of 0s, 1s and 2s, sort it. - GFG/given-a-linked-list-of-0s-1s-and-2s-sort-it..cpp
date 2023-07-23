//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node *start = NULL;


// } Driver Code Ends
/*
 
  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    int count(Node *head, int x){
        int cnt=0;
        while(head){
            if(head->data==x) cnt++;
            head=head->next;
        }
        return cnt;
    }
    Node* segregate(Node *head) {
        
        // Add code here
        int zeros=count(head,0);
        int ones=count(head,1);
        int twos=count(head,2);
        Node* p=new Node(0);
        Node* k=p;
        while(zeros--){
            Node* temp=new Node(0);
            p->next=temp;
            p=temp;
        }
        while(ones--){
            Node* temp=new Node(1);
            p->next=temp;
            p=temp;
        }
        while(twos--){
            Node* temp=new Node(2);
            p->next=temp;
            p=temp;
        }
        return k->next;
    }
};


//{ Driver Code Starts.

// Function to sort a linked list of 0s, 1s and 2s
void printList(struct Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
void insert(int n1) {
    int n, value, i;
    // scanf("%d",&n);
    n = n1;
    struct Node *temp;
    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        if (i == 0) {
            start = new Node(value);
            temp = start;
            continue;
        } else {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

int main() {

    int n;

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        insert(n);
        Solution ob;
        struct Node *newHead = ob.segregate(start);
        printList(newHead);
    }

    return 0;
}
// } Driver Code Ends