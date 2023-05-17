//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        // queue<pair<pair<int,int>,vector<int>>q;
        // priority_queue<>q;
        vector<vector<int>>adj[n+1];
        for(int i = 0 ; i < edges.size() ; i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        priority_queue <pair<int,pair<int,vector<int>>>, vector<pair<int,pair<int,vector<int>>>>, greater<pair<int,pair<int,vector<int>>>> > pq;
        
        pq.push({0,{1,{1}}});
        vector<int>dist(n+1,INT_MAX);
        dist[1]=0;
        // vector<int>ans;
        while(!pq.empty()){
            // for(int t = 0 ; t < sz ; t++){
                pair<int,pair<int,vector<int>>> ki=pq.top();
                pq.pop();
                int dis=ki.first;
                int k=ki.second.first;
                vector<int>vec=ki.second.second;
                vector<int>vy=vec;
                
                if(k==n) return vec;
                
                // cout<<"printing vector : "<<endl;
                // for(auto i:vec) cout<<i<<" ";
                // cout<<endl;
                
                for(int i = 0 ; i < adj[k].size() ; i++){
                    
                    if(dis+adj[k][i][1]<dist[adj[k][i][0]]){
                    dist[adj[k][i][0]]=dis+adj[k][i][1];
                    
                    vy.push_back(adj[k][i][0]);
                    
                    pq.push({dis+adj[k][i][1],{adj[k][i][0],vy}});
                    
                    vy.pop_back();
                    // if(k==n) {ans=vec;cout<<"hi";}
                  }
                }
            // }
        }
        return {-1};
        
        
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