//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        
        // USING SETS
        set<pair<int,int>>st;
        vector<int>dist(V,1e9);
        st.insert({0,S});
        dist[S]=0;
        while(!st.empty()){
            auto p=*(st.begin());
            
            int dis=p.first;
            int k=p.second;
            st.erase(p);
            for(int i = 0 ; i < adj[k].size() ; i++){
                if(dis+adj[k][i][1]<dist[adj[k][i][0]]){
                    if(dist[adj[k][i][0]]!=1e9) 
                    st.erase({dist[adj[k][i][0]],adj[k][i][0]});
                    
                    dist[adj[k][i][0]]=dis+adj[k][i][1];
                    st.insert({dist[adj[k][i][0]],adj[k][i][0]});
                }
            }
        }
        return dist;
        
        /*
        
        USING PRIORITY QUEUE :
        
        //create min heap
        priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > minH;
        minH.push({0,S});
        //create dist array;
        vector<int> dist(V);
        for(int i = 0 ; i < V ; i++) dist[i]=INT_MAX;
        dist[S]=0;
        
        while(!minH.empty()){
            pair<int,int> v=minH.top();
            int k=v.second;
            int dis=v.first;
            minH.pop();
            for(int i = 0 ; i < adj[k].size() ; i++){
                if(dis+adj[k][i][1]<dist[adj[k][i][0]]){
                    dist[adj[k][i][0]]=dis+adj[k][i][1];
                    minH.push({dis+adj[k][i][1],adj[k][i][0]});
                }
            }
        }
        return dist;
        */
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
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends