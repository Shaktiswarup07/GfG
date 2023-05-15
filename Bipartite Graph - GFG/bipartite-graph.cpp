//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool Check(int start,int V , vector<int>adj[],vector<int>&vis){
         queue<int>q;
	    q.push(start);
	    vis[start]=0;
	    while(!q.empty()){
	       // col=!col;
	        int sz=q.size();
	        for(int i = 0 ; i < sz ; i++){
	            int x=q.front();
	            q.pop();
	            for(int j = 0 ; j < adj[x].size() ; j++){
	                if(vis[adj[x][j]]==-1){
	                    q.push(adj[x][j]);
	                    vis[adj[x][j]]=!vis[x];
	                }
	                else{
	                    if(vis[adj[x][j]]==vis[x]) return false;
	                }
	            }
	        }
	    }
	    return true;
    }
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    vector<int>vis(V,-1);
	    for(int i = 0 ; i < V ; i++){
	        if(vis[i]==-1){
	           if(!Check(i,V,adj,vis)) return false;  
	        }
	        
	    }
	    return true;
	   
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends