//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    void createAdjList(Node* root, vector<int>adj[]){
        if(root){
            if(root->left){
                adj[root->data].push_back(root->left->data);
                adj[root->left->data].push_back(root->data);
            }
            if(root->right){
                adj[root->data].push_back(root->right->data);
                adj[root->right->data].push_back(root->data);
            }
            createAdjList(root->left,adj);
            createAdjList(root->right,adj);
        }
    }
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        vector<int>adj[10001];
        createAdjList(root,adj);
        vector<bool>vis(10001,0);
        queue<int>q;
        q.push(target);
        vis[target]=1;
        int tym=0;
        while(!q.empty()){
            tym++;
            int sz=q.size();
            for(int i = 0 ; i <sz ; i++){
                int x=q.front();
                q.pop();
                for(int j = 0 ; j < adj[x].size() ; j++){
                    if(!vis[adj[x][j]]){
                        vis[adj[x][j]]=1;
                        q.push(adj[x][j]);
                    }
                }
            }
        }
    return tym-1;
    }
};

//{ Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}

// } Driver Code Ends