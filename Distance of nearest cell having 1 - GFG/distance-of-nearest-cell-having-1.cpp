//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	    int n=grid.size();
	    int m=grid[0].size();
	    
	    vector<vector<bool>>vis(n,vector<bool>(m,0));
	    vector<vector<int>>ans(n,vector<int>(m,0));
	    
	    queue<pair<pair<int,int>,int>>q;
	    for(int i = 0 ; i < n ; i++){
	        for(int j = 0 ; j < m ; j++){
	            if(grid[i][j]==1){
	                q.push({{i,j},0});
	                vis[i][j]=1;
	            }
	        }
	    }
	    int a[4]={-1,1,0,0};
	    int b[4]={0,0,-1,1};
	    while(!q.empty()){
	        int i=q.front().first.first,j=q.front().first.second;
	        ans[i][j]=q.front().second;
	        int steps=q.front().second;
	        q.pop();
	        for(int k = 0 ; k < 4 ; k++){
	            int newi=i+a[k],newj=j+b[k];
	            if(newi>=0 && newi<n && newj>=0 && newj<m && vis[newi][newj]==0){
	                q.push({{newi,newj},steps+1});
	                vis[newi][newj]=1;
	            }
	        }
	        
	    }
	    return ans;
	    
	    
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends