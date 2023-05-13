//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    void dfss(vector<vector<char>> &mat,int i, int j){
        int n=mat.size(),m=mat[0].size();
        if(i<0 || i>=n || j<0 || j>=m ) return;
        
        mat[i][j]='#';
        int a[4]={-1,1,0,0};
        int b[4]={0,0,-1,1};
        for(int k = 0 ; k< 4 ; k++){
            int nrow=i+a[k],ncol=j+b[k];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && mat[nrow][ncol]=='O') dfss(mat,nrow,ncol);
        }
        // return;
    }
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(i==0 || j==0 || i==n-1 || j==m-1){
                    if(mat[i][j]=='O') dfss(mat,i,j);
                }
            }
        }
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(mat[i][j]=='O') mat[i][j]='X';
                if(mat[i][j]=='#') mat[i][j]='O';
            }
        }
        return mat;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends