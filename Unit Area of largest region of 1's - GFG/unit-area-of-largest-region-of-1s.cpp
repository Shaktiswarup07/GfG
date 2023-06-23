//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find unit area of the largest region of 1s.
    
    void dfs(int i, int j, vector<vector<int>>&grid,int &cnt){
        grid[i][j]=0;
        int a[8]={1,1,0,-1,-1,-1,0,1};
        int b[8]={0,1,1,1,0,-1,-1,-1};
        cnt++;
        for(int k = 0 ; k < 8 ; k++){
            int nrow=i+a[k];
            int ncol=j+b[k];
            if(nrow>=0 && nrow<grid.size() && ncol>=0 && ncol<grid[0].size() && grid[nrow][ncol]==1){
                
                dfs(nrow,ncol,grid,cnt);
            }
        }
    }
    int findMaxArea(vector<vector<int>>& grid) {
        // Code here
        int area=0;
        for(int i = 0 ; i < grid.size() ; i++){
            for(int j = 0 ; j < grid[0].size() ; j++){
                if(grid[i][j]==1){
                    int cnt=0;
                    dfs(i,j,grid,cnt);
                    area=max(area,cnt);
                }
            }
        }
        return area;
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
		int ans = obj.findMaxArea(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends