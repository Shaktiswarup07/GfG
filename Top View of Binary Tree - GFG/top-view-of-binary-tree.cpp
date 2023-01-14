//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

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

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    
    vector<int> topView(Node *root)
    {
        //Your code here
         map<int,map<int,multiset<int>>>mp;
        //  V       L            NODES
        queue<pair<Node*,pair<int,int>>>q;
        //         Node           HOR  LEV
        q.push({root,{0,0}});
        while(!q.empty()){
            pair<Node*,pair<int,int>> temp=q.front();
            q.pop();
            Node *front=temp.first;
            int hd=temp.second.first;
            int lvl=temp.second.second;
            mp[hd][lvl].insert(front->data);
            if(front->left){
                q.push({front->left,{hd-1,lvl+1}});
            }
            if(front->right){
                q.push({front->right,{hd+1,lvl+1}});
            }
        }
        vector<vector<int>> ans;
        for(auto i:mp){
            vector<int>v;
            for(auto j:i.second){
                for(auto k : j.second ) v.push_back(k);
            }
            ans.push_back(v);
        }
        vector<int>vv;
        for(int i=0;i<ans.size();i++){
            vv.push_back(ans[i][0]);
        }
        return vv;
       
    }

};



//{ Driver Code Starts.

int main() {
    int tc;
    cin>>tc;
    cin.ignore(256, '\n');
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Solution ob;
        Node *root = buildTree(treeString);
        vector<int> vec = ob.topView(root);
        for(int x : vec)
            cout<<x<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends