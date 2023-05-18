//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
    void dfs(int i, int j, vector<vector<int>>& matrix){
        int n=matrix.size(),m=matrix[0].size();
        matrix[i][j]=0;
        int a[4]={-1,1,0,0};
        int b[4]={0,0,-1,1};
        for(int k = 0 ; k < 4 ; k++){
            int nrow=i+a[k];
            int ncol=j+b[k];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && matrix[nrow][ncol]==1){
                dfs(nrow,ncol,matrix);
            }
        }
    }
    int closedIslands(vector<vector<int>>& matrix, int N, int M) {
        // Code here
        int n=N,m=M;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(i==0 || j==0 || i==n-1 || j==m-1){
                    if(matrix[i][j]==1) dfs(i,j,matrix);
                }
            }
        }
        int cnt=0;
        for(int i = 0 ; i < n ; i ++){
            for(int j = 0 ; j < m ; j++){
                if(matrix[i][j]==1){
                    dfs(i,j,matrix);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
        int N, M;
        cin >> N >> M;
        vector<vector<int>>matrix(N, vector<int>(M, 0));
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
                cin >> matrix[i][j];
                
        Solution obj;
        int ans = obj.closedIslands(matrix, N, M);
        cout << ans << "\n";
    }
	
	return 0;
	
}


// } Driver Code Ends