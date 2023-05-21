//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int findCity(int n, int m, vector<vector<int>>& edges,int distanceThreshold) {
        //USING DIJKSTRA
        vector<vector<int>> adj[n];
        for(int i=0;i<edges.size() ; i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        int ans=-1,mini=INT_MAX;
        for(int src=0;src<n ; src++){
            priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
            vector<int>dist(n,INT_MAX);
            dist[src]=0;
            pq.push({0,src});
            while(!pq.empty()){
            auto x=pq.top();
            int node=x.second;
            int dis=x.first;
            pq.pop();
            for(int i = 0 ; i < adj[node].size() ; i++){
                if(dis+adj[node][i][1]<dist[adj[node][i][0]]){
                    dist[adj[node][i][0]]=dis+adj[node][i][1];
                    pq.push({dis+adj[node][i][1],adj[node][i][0]});
                    }
                }
            }
            int cnt=0;
            for(int i = 0; i < n ; i++){
                if(dist[i]<=distanceThreshold) cnt++;
            }
            if(cnt<=mini){
                mini=cnt;
                ans=src;
            }
        }
        return ans;
        
        
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;
        // n--;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        int dist;
        cin >> dist;
        Solution obj;
        cout << obj.findCity(n, m, adj, dist) << "\n";
    }
}

// } Driver Code Ends