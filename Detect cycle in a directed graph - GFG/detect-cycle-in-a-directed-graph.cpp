//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCycle(int src, vector<bool>&vis,vector<bool>&pathvis,vector<int>adj[]){
        vis[src]=1;
        pathvis[src]=1;
        for(int i = 0 ; i < adj[src].size() ; i++){
            //when the node is not visited
            if(!vis[adj[src][i]]){
                if(isCycle(adj[src][i],vis,pathvis,adj)==true) return true;
            }
            //when the node is visited on the same path
            else if(vis[adj[src][i]]==1 && pathvis[adj[src][i]]==1) return true;
        }
        pathvis[src]=0;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        /*
        vector<bool>vis(V,0);
        vector<bool>pathvis(V,0);
        for(int i = 0 ; i < V ; i++){
            if(!vis[i]){
                if(isCycle(i,vis,pathvis,adj)==true){
                return true;
               }
            }
        }
        return false;
        */
        // USING TOPO SORT
        vector<int>topo,indegree(V,0);
        for(int i = 0 ; i < V ; i++){
            for(int j = 0 ; j < adj[i].size() ; j++){
                indegree[adj[i][j]]++;
            }
        }
        queue<int>q;
	    for(int i = 0 ; i < V ; i++){
	        if(indegree[i]==0) q.push(i);
	    }
	    while(!q.empty()){
	        int x=q.front();
	        topo.push_back(x);
	        q.pop();
	        for(int i = 0 ; i < adj[x].size() ; i++){
	            indegree[adj[x][i]]--;
	            if(indegree[adj[x][i]]==0) q.push(adj[x][i]);
	        }
	    }
	    return topo.size()==V?0:1;
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
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends