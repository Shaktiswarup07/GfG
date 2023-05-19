//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
const int M=1e9+7;
#define ll long long int
class Solution {
  public:
    int countPaths(int n, vector<vector<int>>& roads) {
        // code here
        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;
        vector<vector<ll>>adj[n];
        for(ll i = 0 ; i< roads.size() ; i++){
            adj[roads[i][0]].push_back({roads[i][1],roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0],roads[i][2]});
        }
        vector<ll>dist(n,1e18);
        vector<ll>ways(n,0);
        ways[0]=1;
        dist[0]=0;
        pq.push({0,0});
        ll cnt=0;
        while(!pq.empty()){
            auto p=pq.top();
            pq.pop();
            ll node=p.second;
            ll dis=p.first;
            if(node==n-1){
                cnt=(cnt+1)%M;
            }
            for(ll i = 0; i < adj[node].size() ; i++){
                if(dis+adj[node][i][1]<dist[adj[node][i][0]]){
                    ways[adj[node][i][0]]=ways[node];
                    dist[adj[node][i][0]]=dis+adj[node][i][1];
                    pq.push({dis+adj[node][i][1],adj[node][i][0]});
                }
                else if(dis+adj[node][i][1]==dist[adj[node][i][0]]){
                    ways[adj[node][i][0]]=(ways[adj[node][i][0]]+ways[node])%M;
                }
            }
        }
        return ways[n-1];
        
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;
        cout << obj.countPaths(n, adj) << "\n";
    }

    return 0;
}
// } Driver Code Ends