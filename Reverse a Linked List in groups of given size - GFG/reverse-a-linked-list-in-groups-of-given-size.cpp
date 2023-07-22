//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


struct node
{
    int data;
    struct node* next;
    
    node(int x){
        data = x;
        next = NULL;
    }
    
};

/* Function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}


// } Driver Code Ends
/*
  Reverse a linked list
  The input list will have at least one element  
  Return the node which points to the head of the new LinkedList
  Node is defined as 
    struct node
    {
        int data;
        struct node* next;
    
        node(int x){
            data = x;
            next = NULL;
        }
    
    }*head;
*/

class Solution
{
    public:
    struct node *Reverse(struct node* &p, int k){
        //i have to return head of reversed k sized linkedlist
        k--;
        struct node* q=p->next;
        p->next=NULL;
        struct node* temp;
        while(k-- && q){
            temp=q->next;
            q->next=p;
            p=q;
            q=temp;
        }
        temp=p;
        p=q;
        return temp;
    }
    struct node *reverse (struct node *head, int k)
    { 
        // Complete this method
        struct node *p = head;
        struct node *res=new node(0);
        struct node *ans=res;
        while(p){
            res->next=Reverse(p,k);
            while(res->next){
                res=res->next;
            }
        }
        return ans->next;
    }
};


//{ Driver Code Starts.

/* Drier program to test above function*/
int main(void)
{
    int t;
    cin>>t;
     
    while(t--)
    {
        struct node* head = NULL;
        struct node* temp = NULL;
        int n;
        cin >> n;
         
        for(int i=0 ; i<n ; i++)
        {
            int value;
            cin >> value;
            if(i == 0)
            {
                head = new node(value);
                temp = head;
            }
            else
            {
                temp->next = new node(value);
                temp = temp->next;
            }
        }
        
        int k;
        cin>>k;
        
        Solution ob;
        head = ob.reverse(head, k);
        printList(head);
    }
     
    return(0);
}


// } Driver Code Ends