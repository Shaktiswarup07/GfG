//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        /*
        vector<vector<int>>adj[n+1];
        for(int i = 0 ; i < edges.size() ; i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        priority_queue <pair<int,pair<int,vector<int>>>, vector<pair<int,pair<int,vector<int>>>>, greater<pair<int,pair<int,vector<int>>>> > pq;
        
        pq.push({0,{1,{1}}});
        vector<int>dist(n+1,INT_MAX);
        dist[1]=0;
        while(!pq.empty()){
                pair<int,pair<int,vector<int>>> ki=pq.top();
                pq.pop();
                int dis=ki.first;
                int k=ki.second.first;
                vector<int>vec=ki.second.second;
                vector<int>vy=vec;
                
                if(k==n) return vec;
                
                
                for(int i = 0 ; i < adj[k].size() ; i++){
                    
                    if(dis+adj[k][i][1]<dist[adj[k][i][0]]){
                    dist[adj[k][i][0]]=dis+adj[k][i][1];
                    
                    vy.push_back(adj[k][i][0]);
                    
                    pq.push({dis+adj[k][i][1],{adj[k][i][0],vy}});
                    
                    vy.pop_back();
                  }
                }
        }
        return {-1};
        */
        
        //ANOTHER APPROACH
            priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
            vector<vector<int>>adj[n+1];
            for(int i = 0 ; i < edges.size() ; i++){
                adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
                adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
            }
            
            pq.push({0,1});
            vector<int>parent(n+1);
            vector<int>dist(n+1,INT_MAX);
            for(int i = 0 ; i <=n ; i++) parent[i]=i;
            dist[1]=0;
            // for(auto i:parent) cout<<i<<" ";
            // cout<<endl;
            while(!pq.empty()){
                auto x=pq.top();
                pq.pop();
                int dis=x.first;
                int k=x.second;
                for(int i = 0 ; i < adj[k].size() ; i++){
                    if(dis+adj[k][i][1]<dist[adj[k][i][0]]){
                        dist[adj[k][i][0]]=dis+adj[k][i][1];
                        pq.push({dist[adj[k][i][0]],adj[k][i][0]});
                        parent[adj[k][i][0]]=k;
                    }
                }
            }
            if(dist[n]==INT_MAX) return {-1};
            vector<int>ans;
            int node=n;
            while(parent[node]!=node){
                ans.push_back(node);
                node=parent[node];
            }
            ans.push_back(1);
            reverse(ans.begin(),ans.end());
            return ans;
            
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
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