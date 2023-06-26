//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    const int M=1e9+7;
    int ncr(int n, int r,vector<vector<int>>&dp){
        if(n==r) return 1;
        if(r==0) return 1;
        if(dp[n][r]!=-1) return dp[n][r];
        
        return dp[n][r]=(ncr(n-1,r-1,dp)%M + ncr(n-1,r,dp)%M)%M;
    }
    int nCr(int n, int r){
        // code here
        if(n<r) return 0;
        // vector<vector<int>>dp(n+1,vector<int>(r+1,0));
        vector<int>prev(r+1,0),cur(r+1,0);
        for(int i = 1 ; i <= n ; i++){
            for(int j = 0 ; j<=r ; j++){
                if(i==j || j==0) cur[j]=1;
                else{
                    cur[j]=(prev[j-1]%M + prev[j]%M)%M;
                }
            }
            prev=cur;
        }
        return prev[r];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}
// } Driver Code Ends