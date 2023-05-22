//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class DisjointSet
{
    vector<int> rank, parent, size;

    public:
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }
    int findUParent(int node)
    {
        if (node == parent[node])
            return node;
        else
            return parent[node] = findUParent(parent[node]);
    }
    void unionByRank(int u, int v)
    {
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);
        if (ulp_u == ulp_v)
        {
            return;
        }
        if (rank[ulp_u] < rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
        }
        else if (ulp_u > ulp_v)
        {
            parent[ulp_v] = ulp_u;
        }
        else
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
    void unionBySize(int u, int v)
    {
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);
        if (ulp_u == ulp_v)
        {
            return;
        }
        if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
	/*
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,0});
        //{weight,node};
        vector<bool>vis(V,0);
        int sum=0;
        while(!pq.empty()){
            auto x=pq.top();
            pq.pop();
            int node=x.second;
            int weight=x.first;
            if(vis[node]==1) continue;
            vis[node]=1;
            sum+=weight;
            for(int i = 0 ; i < adj[node].size() ; i++){
                if(!vis[adj[node][i][0]] ){
                    pq.push({adj[node][i][1],adj[node][i][0]});
                }
            }
        }
        return sum;
	*/
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<pair<int,pair<int,int>>>vec;
        for(int i = 0 ; i < V; i++){
            for(int j = 0; j < adj[i].size() ; j++){
                vec.push_back({adj[i][j][1],{i,adj[i][j][0]}});
            }
        }
        sort(vec.begin(),vec.end());
        int w=0;
        DisjointSet ds(V);
        for(int i = 0 ; i < vec.size() ; i++){
            auto x=vec[i];
            int wt=x.first;
            int u=x.second.first;
            int v=x.second.second;
            
            if(ds.findUParent(u)==ds.findUParent(v)){
                continue;
            }
            else{
                ds.unionByRank(u,v);
                w+=wt;
            }
            
        }
        return w;
        
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends