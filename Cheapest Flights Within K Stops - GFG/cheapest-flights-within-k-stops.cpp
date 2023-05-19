//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
  void Solve(int src,int dst,int k,int &fare, int totCost, vector<pair<int,int>>adj[], vector<bool>&vis){
        if(k<-1){
            return;
        }
        if(src==dst){
            fare=min(fare,totCost);
            return;
        }
        vis[src]=1;
        for(int i = 0 ; i < adj[src].size() ; i++){
            if(!vis[adj[src][i].first] && totCost+adj[src][i].second<=fare){
                Solve(adj[src][i].first,dst,k-1,fare,totCost+adj[src][i].second,adj,vis);
            }
        }
        vis[src]=0;
    }
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int k)  {
        // Code here
        vector<vector<int>>adj[n];
        for(int i = 0 ; i < flights.size() ; i++){
            adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        vector<int>dist(n,INT_MAX);
        dist[src]=0;
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{src,0}});
        //{stops,{node,dist}}
        
        while(!q.empty()){
            auto p=q.front();
            q.pop();
            int stops=p.first;
            int node=p.second.first;
            int dis=p.second.second;
            if(stops>k) continue;
            for(int i = 0 ; i < adj[node].size() ; i++){
                if(dis+adj[node][i][1]<dist[adj[node][i][0]]){
                    dist[adj[node][i][0]]=dis+adj[node][i][1];
                    q.push({stops+1,{adj[node][i][0],dis+adj[node][i][1]}});
                }
            }
        }
        
        if(dist[dst]==INT_MAX) return -1;
        else return dist[dst];
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n; cin>>n;
        int edge; cin>>edge;
        vector<vector<int>> flights;
        
        for(int i=0; i<edge; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            flights.push_back(temp);
        }
        
        int src,dst,k;
        cin>>src>>dst>>k;
        Solution obj;
        cout<<obj.CheapestFLight(n,flights,src,dst,k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends