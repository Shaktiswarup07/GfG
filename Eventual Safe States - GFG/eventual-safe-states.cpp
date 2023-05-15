//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool isCycle(int src, vector<bool>&vis,vector<bool>&pathvis,vector<int>adj[],int check[]){
        vis[src]=1;
        pathvis[src]=1;
        for(int i = 0 ; i < adj[src].size() ; i++){
            //when the node is not visited
            if(!vis[adj[src][i]]){
                if(isCycle(adj[src][i],vis,pathvis,adj,check)==true) {
                    check[src]=0;
                    return true;
                }
            }
            //when the node is visited on the same path
            else if(vis[adj[src][i]]==1 && pathvis[adj[src][i]]==1) {
                check[src]=0;
                return true;
            }
        }
        check[src]=1;
        pathvis[src]=0;
        return false;
    }
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        vector<bool>vis(V,0);
        vector<bool>pathvis(V,0);
        int Check[V]={0};
        vector<int> safeNodes;
        for(int i = 0 ; i < V ; i++){
            if(!vis[i]){
                isCycle(i,vis,pathvis,adj,Check);
            }
        }
        for(int i = 0 ; i < V ; i++){
            if(Check[i]==1) safeNodes.push_back(i);
        }
        return safeNodes;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends