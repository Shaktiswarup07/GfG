//{ Driver Code Starts
#include <bits/stdc++.h>

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};

using namespace std;

void printList(Node *Node)
{
    while (Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->bottom;
    }
}

Node* flatten (Node* root);

int main(void) {

	int t;
	cin>>t;
	while(t--){
    int n,m,flag=1,flag1=1;
    struct Node * temp=NULL;
	struct Node * head=NULL;
	struct Node * pre=NULL;
	struct Node * tempB=NULL;
	struct Node * preB=NULL;
		cin>>n;
        int work[n];
		for(int i=0;i<n;i++)
            cin>>work[i];
		for(int i=0;i<n;i++){
			m=work[i];
			--m;
			int data;
			scanf("%d",&data);
			temp = new Node(data);
			temp->next = NULL;
			temp->bottom = NULL;
			
			if(flag){
				head = temp;
				pre = temp;
				flag = 0;
				flag1 = 1;
			}
			else{
				pre->next = temp;
				pre = temp;
				flag1 = 1;
			}
			for(int j=0;j<m;j++){
				
				int temp_data;
				scanf("%d",&temp_data);
				tempB = new Node(temp_data);

				if(flag1){
					temp->bottom=tempB;
					preB=tempB;
					flag1=0;
				}
				else{
					preB->bottom=tempB;
					preB=tempB;
				}
			}
		}
		   Node *fun = head;
		   Node *fun2=head;

            Node* root = flatten(head);
            printList(root);
            cout<<endl;

	}
	return 0;
}

// } Driver Code Ends


/* Node structure  used in the program

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};
*/

/*  Function which returns the  root of 
    the flattened linked list. */
    Node*head,*temp;
    void Solve(Node* root){
        if(root==NULL) return;
        Solve(root->next);
        Node* p=root->next;
        temp=new Node(0);
        head=NULL;
        while(root && p){
            if(root->data<=p->data){
                // cout<<root->data<<endl;
                if(head==NULL){head=root; temp=root;}
                else{
                    temp->bottom=root;temp=root;
                    
                }
                root=root->bottom;
            }
            else{
                // cout<<p->data<<endl;
                if(head==NULL){head=p; temp=p;}
                else{
                    temp->bottom=p;temp=p;
                    
                }
                p=p->bottom;
            }
        }
        if(root){
            // if(temp==NULL) temp=root;
            // else 
            temp->bottom=root;
            // if(head==NULL){head=root;temp=root;}
            // else{temp->bottom=root;}
        }
        if(p){
            // if(temp==NULL) temp=p;
            // else
            temp->bottom=p;
            // if(head==NULL){head=p;temp=p;}
            // else{temp->bottom=p;}
        }
        // Node* k=head;
        // while(k){
        //     cout<<k->data<<endl;
        //     k=k->bottom;
        // }
        // cout<<"------------------------"<<endl;
        // temp=head;
        
    }
Node *flatten(Node *root)
{
   // Your code here
   if(root->next==NULL) return root;
   Solve(root);
   head->next=NULL;
   return head;
}

