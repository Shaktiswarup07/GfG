//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Linked List Node
struct Node
{
	Node* next;
	int data;
};

// Utility function to insert a node at the
// beginning
void push(Node** head, int data)
{
	Node* newNode = new Node;
	newNode->next = (*head);
	newNode->data = data;
	(*head) = newNode;
}

// Utility function to print a linked list
void printList(Node* head)
{
	while (head != NULL)
	{
		cout << head->data;
		if (head->next != NULL)
			cout << " ";
		head = head->next;
	}
	cout << endl;
}


// } Driver Code Ends
/* The structure of the Linked list Node is as follows:
struct Node
{
    Node* next;
    int data;
}; */

/*Your method shouldn't print anything
 it should transform the passed linked list */
class Solution{
    
public:
    Node* sortList(Node* head)
    {
        // Your Code Here
        Node *posNode=new Node;
        Node *p=posNode;
        Node *negNode=new Node;
        Node *n=negNode;
        Node *t;
        while(head){
            if(head->data>=0){
                t=new Node;
                t->data=head->data;
                t->next=NULL;
                p->next=t;
                p=t;
            }
            else {
                t=new Node;
                t->data=head->data;
                t->next=NULL;
                n->next=t;
                n=t;
            }
            head=head->next;
        }
        if(negNode->next==NULL) return posNode->next;
        
        // return posNode; 0 1 4
        // return negNode; 0 -2 -3 -5
        // we need -5 -3 -2 1 4
        
        posNode=posNode->next;
        negNode=negNode->next;
        // we need to reverse neg Node
        Node *m=negNode;
        Node *k=NULL;
        Node *j;
        while(m){
            j=m->next;
            m->next=k;
            k=m;
            m=j;
        }
        negNode->next=posNode;
        return k;
        
    }
};


//{ Driver Code Starts.

// Driver code
int main()
{

	int t = 0;
	int n = 0;
	cin >> t;
	while (t--)
	{
		Node* head = NULL;
		cin >> n;
		int arr[n];
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
			// push(&head, a);
		}
		for (int i = n - 1; i >= 0; i--)
		{
			push(&head, arr[i]);
		}
		// printList(head);
		
		Solution ob;
		head=ob.sortList(head);

		printList(head);

	}
	return 0;
}

// } Driver Code Ends