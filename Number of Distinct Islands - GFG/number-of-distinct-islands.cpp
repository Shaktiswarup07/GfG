//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void dfs(int i, int j, vector<vector<int>>& grid, vector<pair<int,int>>&vec,int orow, int ocol){
        int n=grid.size(),m=grid[0].size();
        grid[i][j]=0;
        int a[4]={-1,1,0,0};
        int b[4]={0,0,-1,1};
        for(int k = 0 ; k < 4 ; k++){
            int nrow=i+a[k], ncol=j+b[k];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1){
                vec.push_back({nrow-orow,ncol-ocol});
                dfs(nrow,ncol,grid,vec,orow,ocol);
            }
        }
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n=grid.size(),m=grid[0].size();
        set<vector<pair<int,int>>>st;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j]==1){
                    vector<pair<int,int>>vec;
                    dfs(i,j,grid,vec,i,j);
                    st.insert(vec);
                }
            }
        }
        return st.size();
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
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends