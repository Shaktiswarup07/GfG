//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
	    // Code here
	    vector<int>adj[N];
	    for(int i = 0 ; i < prerequisites.size() ; i++){
	        adj[prerequisites[i].second].push_back(prerequisites[i].first);
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
	    return topo.size()==N?1:0;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends