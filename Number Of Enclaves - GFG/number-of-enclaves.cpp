//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void dfss(int i,int j, vector<vector<int>> &grid){
        int n=grid.size(),m=grid[0].size();
        grid[i][j]=2;
        int a[4]={-1,1,0,0};
        int b[4]={0,0,-1,1};
        for(int k = 0 ; k < 4 ; k++){
            int nrow=i+a[k],ncol=j+b[k];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1){
                dfss(nrow,ncol,grid);
            }
        }
    }
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        int n=grid.size(),m=grid[0].size();
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(i==0 || i==n-1 || j==0 || j==m-1){
                    if(grid[i][j]==1)
                    dfss(i,j,grid);
                }
            }
        }
        
        int cnt=0;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j]==1){
                    cnt++;
                }
                else if(grid[i][j]==2) grid[i][j]=1;
            }
        }
        return cnt;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends