//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int Solve(int n, int W, int val[], int wt[], vector<vector<int>>&dp){
        if(n==0 || W==0) return 0;
        
        if(dp[n][W]!=-1) return dp[n][W];
        int npick=Solve(n-1,W,val,wt,dp);
        int pick=INT_MIN;
        if(W>=wt[n-1]) pick=val[n-1]+Solve(n,W-wt[n-1],val,wt,dp);
        return dp[n][W]=max(pick,npick);
    }
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        vector<vector<int>>dp(N+1,vector<int>(W+1,-1));
        return Solve(N,W,val,wt,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends