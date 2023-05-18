//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  /*
    int bfs(int src, int tar, vector<int>adj[],int m,int n){
        vector<bool>vis(m*n,0);
        queue<int>q;
        q.push(src);
        vis[src]=1;
        int cnt=0;
        while(!q.empty()){
            int sz=q.size();
            for(int i = 0 ; i < sz ; i++){
                int node=q.front();
                if(node==tar) return cnt;
                q.pop();
                for(int j = 0 ; j < adj[node].size() ; j++){
                    if(!vis[adj[node][j]]){
                        q.push(adj[node][j]);
                        vis[adj[node][j]]=1;
                    }
                }
            }
            cnt++;
        }
        return -1;
    }
    */
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        // code here
        /*
        int n=grid.size();
        int m=grid[0].size();
        vector<int>adj[n*m];
        vector<vector<int>>gri(n,vector<int>(m,0));
        int srci=source.first,srcj=source.second;
        int tari=destination.first,tarj=destination.second;
        int c=0;
        int src,target;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(i==tari && j==tarj) target=c;
                if(i==srci && j==srcj) src=c;
                gri[i][j]=c;
                c++;
            }
        }
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j]==1){
                    if(i-1>=0 && grid[i-1][j]==1) adj[gri[i][j]].push_back(gri[i-1][j]);
                    if(j+1<m && grid[i][j+1]==1) adj[gri[i][j]].push_back(gri[i][j+1]);
                    if(i+1<n && grid[i+1][j]==1) adj[gri[i][j]].push_back(gri[i+1][j]);
                    if(j-1>=0 && grid[i][j-1]==1) adj[gri[i][j]].push_back(gri[i][j-1]);
                }
            }
        }
        
        int ans=0;
        ans=bfs(src,target,adj,m,n);
        return ans;
        */
        //ANOTHER APPROACH
        int n=grid.size();
        int m=grid[0].size();
        int si=source.first,sj=source.second;
        int ti=destination.first,tj=destination.second;
        vector<vector<int>> dist(grid.size(),vector<int>(grid[0].size(),INT_MAX));
        dist[si][sj]=0;
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{si,sj}});
        
        int a[4]={-1,1,0,0};
        int b[4]={0,0,-1,1};
        while(!q.empty()){
            auto x=q.front();
            q.pop();
            int dis=x.first;
            int i1=x.second.first;
            int j1=x.second.second;
            for(int i = 0 ; i < 4 ; i++){
                int nrow=i1+a[i];
                int ncol=j1+b[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1 && dis+1<dist[nrow][ncol]){
                    dist[nrow][ncol]=dis+1;
                    q.push({dis+1,{nrow,ncol}});
                }
            }
            if(dist[ti][tj]!=INT_MAX) return dist[ti][tj];
            
        }
        return -1;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends