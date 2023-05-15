//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
  public:
    vector<int> findOrder(int n, int m, vector<vector<int>> prerequisites) 
    {
        //code here
        int N=n;
		vector<int>emptyVec;
        vector<int>adj[N];
	    for(int i = 0 ; i < prerequisites.size() ; i++){
	        adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
	    }
	    int V=N;
	    vector<int>topo;
	    vector<int>indegree(V,0);
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
	    return topo.size()==N?topo:emptyVec;
    }
};

//{ Driver Code Starts.

int check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> prerequisites;

        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            prerequisites.push_back({u,v});
        }
        
        vector<int> adj[n];
        for (auto pre : prerequisites)
            adj[pre[1]].push_back(pre[0]);
        
        Solution obj;
        vector <int> res = obj.findOrder(n, m, prerequisites);
        if(!res.size())
            cout<<"No Ordering Possible"<<endl;
        else
            cout << check(n, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends