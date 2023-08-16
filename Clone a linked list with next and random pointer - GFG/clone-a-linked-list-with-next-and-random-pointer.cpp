//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
/* Link list Node */
struct Node {
    int data;
    Node *next;
    Node *arb;

    Node(int x) {
        data = x;
        next = NULL;
        arb = NULL;
    }
};



// } Driver Code Ends
class Solution
{
    public:
    Node *copyList(Node *head)
    {
        //Write your code here
        map<Node*,int>mp;
        Node* temp=head;
        int count=0;
        while(temp){
            mp[temp]=count;
            count++;
            temp=temp->next;
        }
        map<int,Node*>m;
        temp=head;
        count=0;
        while(temp){
            m[count]=temp;
            count++;
            temp=temp->next;
        }
        
        Node* temp2=head;
        map<int,int>m2;
        // temp=head;
        count=0;
        while(temp2){
            if(temp2->arb){
                m2[count]=mp[temp2->arb];
            }
            count++;
            temp2=temp2->next;
        }
        // cout<<m2[0]<<" "<<m2[2]<<endl;
        Node *chead=new Node(head->data);
        Node *t = chead;
        temp2=head->next;
        while(temp2){
            Node* t1=new Node(temp2->data);
            t->next=t1;
            t=t1;
            temp2=temp2->next;
        }
        
        // map<Node*,int>mp;
         temp=chead;
         count=0;
        while(temp){
            mp[temp]=count;
            count++;
            temp=temp->next;
        }
        // map<int,Node*>m;
        temp=chead;
        count=0;
        while(temp){
            m[count]=temp;
            count++;
            temp=temp->next;
        }
        
        temp=chead;
        int cnt=0;
        while(temp){
            if(m2.find(cnt)!=m2.end()){
                temp->arb=m[m2[cnt]];
                // cout<<temp->data<<" "<<temp->arb->data<<endl;
            }
            cnt++;
            temp=temp->next;
        }
        return chead;
        
        
    }

};

//{ Driver Code Starts.


void print(Node *root) {
    Node *temp = root;
    while (temp != NULL) {
        int k;
        if (temp->arb == NULL)
            k = -1;
        else
            k = temp->arb->data;
        cout << temp->data << " " << k << " ";
        temp = temp->next;
    }
}


void append(Node **head_ref, Node **tail_ref, int new_data) {

    Node *new_node = new Node(new_data);
    if (*head_ref == NULL) {
        *head_ref = new_node;
    } else
        (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}

bool validation(Node *head, Node *res) {


    Node *temp1 = head;
    Node *temp2 = res;

    int len1 = 0, len2 = 0;
    while (temp1 != NULL) {
        len1++;
        temp1 = temp1->next;
    }
    while (temp2 != NULL) {
        len2++;
        temp2 = temp2->next;
    }

    /*if lengths not equal */

    if (len1 != len2) return false;

    temp1 = head;
    temp2 = res;
    map<Node*,Node*> a;
    while (temp1 != NULL) {
        
        if(temp1==temp2)
            return false;
        
        if (temp1->data != temp2->data) return false;
        if (temp1->arb != NULL and temp2->arb != NULL) {
            if (temp1->arb->data != temp2->arb->data)
                return false;
        } else if (temp1->arb != NULL and temp2->arb == NULL)
            return false;
          else if (temp1->arb == NULL and temp2->arb != NULL)
            return false;
        a[temp1]=temp2;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    

    temp1 = head;
    temp2 = res;
    while (temp1 != NULL) {
        
        if (temp1->arb != NULL and temp2->arb != NULL) {
            if (a[temp1->arb] != temp2->arb) return false;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return true;
}



int main() {

    int T, i, n, l, k;
    Node *generated_addr = NULL;
     /*reading input stuff*/
    cin >> T;
    while (T--) {
        generated_addr = NULL;
        struct Node *head = NULL, *tail = NULL;
        struct Node *head2 = NULL, *tail2 = NULL;
        cin >> n >> k;
        for (i = 1; i <= n; i++) {
            cin >> l;
            append(&head, &tail, l);
            append(&head2, &tail2, l);
        }
         for (int i = 0; i < k; i++) {
            int a, b;
            cin >> a >> b;

            Node *tempA = head;
            Node *temp2A = head2;
            int count = -1;

            while (tempA != NULL) {
                count++;
                if (count == a - 1) break;
                tempA = tempA->next;
                temp2A = temp2A->next;
            }
            Node *tempB = head;
            Node *temp2B = head2;
            count = -1;

            while (tempB != NULL) {
                count++;
                if (count == b - 1) break;
                tempB = tempB->next;
                temp2B = temp2B->next;
            }

            // when both a is greater than N
            if (a <= n){
                tempA->arb = tempB;
                temp2A->arb = temp2B;
            }
        }
        /*read finished*/

        generated_addr = head;
        Solution ob;
        struct Node *res = ob.copyList(head);
        if(validation(head2,res)&&validation(head,res))
            cout << validation(head2, res) << endl;
        else
            cout << 0 << endl;
    }
    return 0;
}
// } Driver Code Ends