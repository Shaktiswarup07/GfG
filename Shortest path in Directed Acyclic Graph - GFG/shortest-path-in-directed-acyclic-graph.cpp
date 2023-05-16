//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
     void topoSort(int node, vector<pair<int,int>>adj[], int vis[] , stack<int>&st){
         vis[node]=1;
         for(int i = 0 ; i < adj[node].size() ; i++){
             if(!vis[adj[node][i].first]){
                 topoSort(adj[node][i].first,adj,vis,st);
             }
         }
         st.push(node);
     }
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        // N vertices
        // M edges
        vector<pair<int,int>>adj[N];
        for(int i = 0 ; i < M ; i++){
            int a=edges[i][0],b=edges[i][1],c=edges[i][2];
            adj[a].push_back({b,c});
        }
        
        // STEP - 1 Find the Topo Sort
        
        int vis[N]={0};
        stack<int>st;
        for(int i = 0 ; i < N ; i++){
            if(!vis[i]){
                topoSort(i,adj,vis,st);
            }
        }
        
        //STEP - 2 : Do the distance thing...
        while(st.top()!=0){
            st.pop();
        }
        vector<int>dist(N);
        for(int i = 0 ; i < N ; i++) dist[i]=INT_MAX;
        dist[0]=0;
        while(!st.empty()){
            int node=st.top();
            st.pop();
            for(int i = 0 ; i < adj[node].size() ; i++){
                if(dist[node]+adj[node][i].second<dist[adj[node][i].first])
                dist[adj[node][i].first]=dist[node]+adj[node][i].second;
            }
        }
        for(int i = 0 ; i < N ; i++){
            if(dist[i]==INT_MAX) dist[i]=-1;
        }
        return dist;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends