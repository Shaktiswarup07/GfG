//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int findCity(int N, int M, vector<vector<int>>& edges,
                 int distanceThreshold) {
        vector<vector<int>>matrix(N,vector<int>(N,1e9));
        for(int i = 0 ; i < edges.size() ; i++){
            // for(int j = 0 ; j < edges[0].size() ; j++){
                matrix[edges[i][0]][edges[i][1]]=edges[i][2];
                matrix[edges[i][1]][edges[i][0]]=edges[i][2];
            // }
        }
        int n=matrix.size(),m=matrix[0].size();
	    for(int i = 0 ; i < n ; i++){
	        for(int j = 0 ; j < m ; j++){
	            if(i==j) matrix[i][j]=0;
	        }
	    }
	    for(int k = 0 ; k < n ; k++){
	        for(int i = 0 ; i < n ; i++){
	            for(int j = 0 ; j < m ; j++){
	                matrix[i][j]=min(matrix[i][j],matrix[i][k]+matrix[k][j]);
	            }
	        }
	    }
	    int mini=INT_MAX;
	    int ans=0;
	    for(int i = 0 ; i < n ; i++){
	        int cnt=0;
	        for(int j = 0 ; j < m ; j++){
	           // if(matrix[i][j]==1e9) matrix[i][j]=-1;
	           //cout<<matrix[i][j]<<" ";
	           if(matrix[i][j]<=distanceThreshold) cnt++;
	        }
	        if(cnt<=mini){
	            mini=cnt;
	            ans=i;
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