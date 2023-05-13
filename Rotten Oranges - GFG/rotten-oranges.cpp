//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int n=grid.size(),m=grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,0));
        queue<pair<int,int>>q;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                    vis[i][j]=1;
                }
            }
        }
        int a[4]={-1,1,0,0};
        int b[4]={0,0,-1,1};
        int time=0;
        while(!q.empty()){
            int sz=q.size();
            bool f=0;
            for(int i = 0 ; i < sz ; i++){
                int row=q.front().first,col=q.front().second;
                q.pop();
                
                for(int k=0; k < 4 ; k++){
                    int nrow=row+a[k],ncol=col+b[k];
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]==1){
                        grid[nrow][ncol]=2;
                        q.push({nrow,ncol});
                        vis[nrow][ncol]=1;
                        f=1;
                    }
                }
            }
            if(f) time++;
        }
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j]==1) return -1;
            }
        }
        return time;
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
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends