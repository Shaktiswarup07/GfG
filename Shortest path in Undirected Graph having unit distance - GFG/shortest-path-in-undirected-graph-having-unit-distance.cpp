//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    void bfs(int src, vector<int>adj[], vector<int>&dist,int V){
        queue<int>q;
        vector<bool> vis(V,0);
        q.push(src);
        vis[src]=1;
        int cnt=0;
        while(!q.empty()){
            int sz=q.size();
            for(int i = 0; i<sz ; i++){
                int x=q.front();
                dist[x]=cnt;
                q.pop();
                for(int j = 0; j < adj[x].size() ; j++){
                    if(!vis[adj[x][j]]){
                        q.push(adj[x][j]);
                        vis[adj[x][j]]=1;
                    }
                }
            }
            cnt++;
        }
    }
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        // code here
        vector<int>dist(N);
        for(int i = 0 ; i < N ; i++) dist[i]=-1;
        vector<int>adj[N];
        for(int i = 0 ; i < edges.size() ; i++){
            int u=edges[i][0],v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        bfs(src,adj,dist,N);
        return dist;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends